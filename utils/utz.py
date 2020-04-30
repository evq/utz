#!/usr/bin/env python3

""" Library for parsing IANA timezone files and performing transformations

eV Quirk
"""

from collections import OrderedDict
from datetime import date
from functools import total_ordering
from typing import List, Tuple, Dict

CURRENT_YEAR = date.today().year
MAX_FMT_LEN = 5

TZ_TYPES: List[str] = ['Rule', 'Zone', 'Link']

DAY_OF_WEEK: List[str] = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
MONTHS: List[str] = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun',
                     'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']


class Entry(object):
    column_names = ()
    opt_columns = ()

    def __init__(self, *args, **kwargs):
        self.num_columns = len(self.column_names)
        self.num_opt_columns = len(self.opt_columns)
        self.values = [None] * self.num_columns
        if args or kwargs:
            self._load(*args, **kwargs)
            # default "source" in cases we dont use self.load
            self._src = self.dumps(clazz=False)

    def __getattr__(self, name):
        return self.values[self.column_names.index(name)]

    def __repr__(self):
        return str(self.values)

    def _load(self, *args, **kwargs):
        for i in range(self.num_columns - self.num_opt_columns):
            self.values[i] = args[i]
        if self.opt_columns:
            for i in range(self.num_opt_columns):
                j = self.num_columns - self.num_opt_columns + i
                if self.opt_columns[i] in kwargs:
                    self.values[j] = kwargs[self.opt_columns[i]]
                elif len(args) - 1 >= j:
                    self.values[j] = args[j]

    def dumps(self, clazz=True):
        tmp = ''
        if clazz:
            tmp = tmp + self.__class__.__name__ + '\t'
        tmp += '\t'.join(self.values[:self.num_columns-self.num_opt_columns])
        for i in range(self.num_opt_columns):
            j = self.num_columns - self.num_opt_columns + i
            if self.values[j] is not None:
                tmp += '\t' + self.values[j]
        return tmp

    @classmethod
    def loads(cls, string: str):
        new = cls()
        split_line = string.split(None, new.num_columns-1)
        new._load(*split_line)
        new._src = string
        return new


def parse_h_m(time: str) -> Tuple[str, int, int]:
    z, h, m = ('local', 0, 0)
    if time.endswith('u'):
        z = 'utc'
        time = time[:len(time)-2]
    if time.endswith('s'):
        z = 'standard'
        time = time[:len(time)-2]

    if ':' in time:
        h, m = [int(s) for s in time.split(':')]
    else:
        h = int(time)
    return z, h, m


class Rule(Entry):
    # Rule	NAME	FROM	TO	TYPE	IN	ON	AT	SAVE	LETTER
    column_names = ('name', '_from', 'to', 'type', '_in',
                    'on', 'at', 'save', 'letter',)

    def pack(self) -> str:
        """ Pack rule into micro timezone rule format, only works after stripping historical zones / rules """
        _from = int(self._from) - 2000
        if _from < 0:
            _from = 0

        if self.to == 'only':
            to = _from
        elif self.to == 'max':
            to = 255
        else:
            to = int(self.to) - 2000

        in_month = MONTHS.index(self._in)+1

        on_dow = 0
        on_dom = 0

        if '>=' in self.on:
            on_dow, on_dom = self.on.split('>=')
            on_dom = int(on_dom)
        elif 'last' in self.on:
            on_dow = self.on[4:]
        else:
            on_dom = int(self.on)

        if not isinstance(on_dow, int):
            on_dow = DAY_OF_WEEK.index(on_dow) + 1

        _, off_H, _ = parse_h_m(self.save)

        at_z, at_H, at_M = parse_h_m(self.at)
        if at_z == 'utc':
            at_z = 0
        elif at_z == 'standard':
            at_z = 1
        elif at_z == 'local':  # we convert all rules specified in local time to standard time
            on_dow, on_dom, at_H, off_H = w_to_s(
                on_dow, on_dom, at_H, off_H)
            at_z = 1
        l = 2 if self.letter == 'D' else 1 if self.letter == 'S' else 0

        # see utz.h for struct definitions
        return f"{{{_from:3}, {to:3}, {on_dow}, {on_dom:2}, {at_z:2}, {at_H:2}, {int(at_M/15)}, {l}, {in_month:2}, {off_H}}}, // {self._src}"


def w_to_s(on_dow, on_dom, at_H, off_H) -> Tuple[int, int, int, int]:
    """ Converts a rule with a local (wall) time to standard time """

    if off_H == 0:
        # Rule is for going back to standard time, which means it's currently on savings time.
        # Change back to standard, which means moving an hour back
        if at_H == 0:
            # if at_H is 0, going back to std time means going back to the previous day
            if on_dow != 0 and on_dom != 0:  # rule specifies day of week and day of month, ex Sun>=1
                on_dow = on_dow - 1 if on_dow - 1 > 0 else 7
                on_dom = on_dom - 1
                assert(on_dom > 0)
                at_H = 23
            elif on_dow == 0:  # format is day of month, ex 21
                on_dom = on_dom - 1
                assert(on_dom > 0)
                at_H = 23
            elif on_dom == 0:  # format is day of week, ex: lastSun
                # the three rule groups that hit this condition are Mongol, Lebanon, and Syria

                # they rely on lastDOW (e.g. lastSun, unfortunately there
                # isn't an easy way to specify lastSun-1 ) as far as I can tell

                # selfishly I'm going to take the hit of being 1 hour off on these 3 zones :/
                pass
        else:  # same day, just go back an hour to std time
            at_H = at_H - 1
    return (on_dow, on_dom, at_H, off_H)


@total_ordering
class Zone(Entry):
    # Zone	NAME	STDOFF	RULES	FORMAT	[UNTIL]
    column_names = ('name', 'stdoff', 'rules', 'format', 'until',)
    opt_columns = ('until',)

    def __eq__(self, other) -> bool:
        return self.name == other.name

    def __lt__(self, other):
        return self.name < other.name

    def pack(self, rule_groups, rule_group_starts, formatters):
        if self.until is not None:
            print(self)  # FIXME warnings

        _, h, m = parse_h_m(self.stdoff)
        if (h < 0):
            m = -m
        #fmt = self.format
        # if '+' in fmt or '-' in fmt:
        #    fmt = '-'  # we will assume there is no abrev and generate from offset
        # if '/' in fmt and 'GMT' in fmt:
        #    fmt = fmt[fmt.index('/'):]  # assume starts with / means GMT/<foo>
        fmt = 0
        if self.format in formatters:
            fmt = formatters[self.format]['start']

        #fmt_a = []
        # for i in range(MAX_FMT_LEN):
            # if len(fmt) > i:
            #    fmt_a.append("%4s" % ("'" + fmt[i] + "'"))
            # else:
            #    fmt_a.append("%4s" % "'\\0'")

        rule_start = 0
        num_rule = 0
        if self.rules != '-':
            rule_start = rule_group_starts[self.rules]
            num_rule = len(rule_groups[self.rules])

        return f"{{{(4 * h) + (m / 15):3.0f}, {rule_start:3}, {num_rule:3}, {fmt:3}}},"


class Link(Entry):
    # Link  FROM    TO
    column_names = ('_from', 'to',)


class TimeZoneDatabase(object):
    def __init__(self):
        self.rules: List[Rule] = []
        self.zones: List[Zone] = []
        self.links: List[Link] = []

    def load(self, f):
        """ Reads Rules, Zones, and Links from tz data files into python objects """

        for line in f:
            try:
                line = line[:line.index('#')]
            except:
                pass
            line = line.strip()
            if len(line) <= 1:
                continue
            for k in TZ_TYPES:
                if line.startswith(k):
                    line = line[len(k):]
                    if k == 'Rule':
                        self.rules.append(Rule.loads(line))
                    if k == 'Zone':
                        self.zones.append(Zone.loads(line))
                    if k == 'Link':
                        self.links.append(Link.loads(line))
                    break
            else:
                # Must be a multi-line zone (I hope ffs), use the last zonename
                tmp = [self.zones[-1].name]
                tmp.extend(line.split(None, len(Zone.column_names)-1))
                self.zones.append(Zone(*tmp))

    def dump(self, f) -> None:
        """ Serializes the Rules, Zones, and Links and writes them to a file """

        for rule in self.rules:
            f.write(rule.dumps() + '\n')
        for zone in self.zones:
            f.write(zone.dumps() + '\n')
        for link in self.links:
            f.write(link.dumps() + '\n')

    def strip_historical(self) -> None:
        """ Strip out historical rules and zones """

        rule_group_names = set()

        filtered_rules = []
        for rule in self.rules:
            if rule.to == 'only' and int(rule._from) < CURRENT_YEAR:
                continue
            if ((rule.to == 'max') or (rule.to == 'only') or (int(rule.to) >= CURRENT_YEAR)):
                filtered_rules.append(rule)
                rule_group_names.add(rule.name)
        self.rules = filtered_rules

        filtered_zones = []
        for zone in self.zones:
            # We might have pruned all the rules for this zone above
            if zone.rules != '-' and zone.rules not in rule_group_names:
                zone.rules = '-'
                if '%' in zone.format:
                    zone.format = zone.format % 'S'

            if zone.until is None or int(zone.until[:4]) >= CURRENT_YEAR:
                filtered_zones.append(zone)
        self.zones = filtered_zones

    def rule_groups(self) -> Dict[str, List[Rule]]:
        """ Groups rules by name, also prune orphaned rules """

        rule_groups: Dict[str, List[Rule]] = {}
        for rule in self.rules:
            if rule.name in rule_groups:
                rule_groups[rule.name].append(rule)
            else:
                rule_groups[rule.name] = [rule]
        for group in rule_groups.keys():
            for zone in self.zones:
                if group == zone.rules:
                    break
            else:
                del rule_groups[group]
        return rule_groups

    def pack(self, h_filename: str, included_aliases: List[str] = []) -> Tuple[str, str]:
        whitelisted_zones: List[str] = []
        for alias in included_aliases:
            for link in self.links:
                if link.to == alias or link._from == alias:
                    whitelisted_zones.append(link._from)

        whitelisted_rules = []
        zones: List[Zone] = []
        for zone in self.zones:
            if zone.name in whitelisted_zones:
                zones.append(zone)
                if zone.rules != '-':
                    whitelisted_rules.append(zone.rules)
        self.zones = zones

        rules = []
        for ruleset in self.rules:
            if ruleset.name in whitelisted_rules:
                rules.append(ruleset)
        self.rules = rules

        h_guard = '_' + h_filename.upper().replace('.', '_')
        h_buf = [f'#ifndef {h_guard}', f'#define {h_guard}', '']
        c_buf = ['#include "utz.h"', '']
        rule_groups = self.rule_groups()
        rule_group_starts = self._pack_rules(rule_groups, c_buf, h_buf)
        c_buf.append('')
        zone_indexes = self._pack_zones(
            rule_groups, rule_group_starts, c_buf, h_buf)
        c_buf.append('')
        self._pack_links(zone_indexes, c_buf, h_buf, included_aliases)
        c_buf.append('')
        h_buf.append(f'#endif /* {h_guard} */')
        return ('\n'.join(c_buf), '\n'.join(h_buf))

    def _pack_rules(self, rule_groups: Dict[str, List[Rule]], c_buf: List[str], h_buf: List[str]):
        c_buf.append('PLACEHOLDER')
        group_idx = {}
        idx = 0
        for name, group in sorted(rule_groups.items()):
            group_idx[name] = idx
            # Assumes only one rule per month
            for rule in sorted(group, key=lambda x: MONTHS.index(x._in)):
                c_buf.append(rule.pack())
                idx = idx + 1
        c_buf[c_buf.index('PLACEHOLDER')
              ] = f'const urule_packed_t zone_rules[{idx}] = {{'
        c_buf.append('};')
        h_buf.append(f'const urule_packed_t zone_rules[{idx}];')

        return group_idx

    def _pack_zones(self, rule_groups, rule_group_starts, c_buf, h_buf):
        packed_zones = OrderedDict()
        packed_formatters = OrderedDict()
        zone_indexes: Dict[str, int] = {}

        for zone in sorted(self.zones):
            fmt = zone.format
            if fmt not in packed_formatters:
                packed_formatters[fmt] = {'fmt': fmt}

        c_buf.append('PLACEHOLDER')
        total_char = 0
        max_char = 0
        for orig_fmt, packed_fmt in packed_formatters.items():
            packed_formatters[orig_fmt]['start'] = total_char
            if '%' in packed_fmt['fmt']:
                packed_fmt['fmt'] = packed_fmt['fmt'] % '%c'
            c_buf.append("'%s','\\0'," % "','".join(
                [c for c in packed_fmt['fmt']]))
            total_char += len(packed_fmt['fmt']) + 1
            if len(packed_fmt['fmt']) > max_char:
                max_char = len(packed_fmt['fmt'])

        c_buf.append('};')
        c_buf.append('')
        c_buf[c_buf.index('PLACEHOLDER')
              ] = f'const char zone_abrevs[{total_char}] = {{'
        h_buf.extend(
            [f'const char zone_abrevs[{total_char}];', ''])
        h_buf.extend([f'#define MAX_ABREV_FORMATTER_LEN {max_char}', ''])

        for zone in sorted(self.zones):
            packed_zone = zone.pack(
                rule_groups, rule_group_starts, packed_formatters)
            if packed_zone not in packed_zones:
                packed_zones[packed_zone] = []
            packed_zones[packed_zone].append(zone)
            zone_indexes[zone.name] = list(packed_zones).index(packed_zone)

        c_buf.append(
            f'const uzone_packed_t zone_defns[{len(packed_zones)}] = {{')
        for packed_zone, srcs in packed_zones.items():
            for src_zone in srcs:
                c_buf.append('// ' + src_zone._src)
            c_buf.append(packed_zone)
        c_buf.append('};')
        h_buf.append(
            f'const uzone_packed_t zone_defns[{len(packed_zones)}];')

        return zone_indexes

    def _pack_links(self, zone_indexes, c_buf, h_buf, included_aliases=[]):
        for link in self.links:
            if link._from in zone_indexes:
                zone_indexes[link.to] = zone_indexes[link._from]

        aliases = {}
        max_len = 0
        for name, index in zone_indexes.items():
            if '/' in name:  # The only zones without / are "legacy aliases" like EST, PST etc
                if not included_aliases or name in included_aliases:
                    name = name.split('/')[-1]
                    aliases[name] = index
                    if len(name) > max_len:
                        max_len = len(name)

        c_buf.append('PLACEHOLDER')
        total_char = 0
        max_char = 0
        for i, (name, index) in enumerate(sorted(aliases.items())):
            char = []
            orig_name = name
            name = name.replace("'", '')
            name = name.replace("-", '')
            name = name.replace(".", '')
            name = name.replace(",", '')
            h_buf.append(("#define UTZ_" + name.upper() + ' ' *
                          (max_len+4-len(name)) + f'&zone_defns[{index:3}]'))
            name = orig_name.replace('_', ' ')
            for c in name:
                if c == "'":
                    char.append("\\'")
                else:
                    char.append(c)
            char.append('\\0')
            total_char += len(char) + 1
            if len(char) > max_char:
                max_char = len(char)
            c_buf.append(("%" + str(max_len*5) + "s, %3d, // %s") %
                         ("'%s'" % "','".join(char), index, name))
        c_buf[c_buf.index(
            'PLACEHOLDER')] = f'const unsigned char zone_names[{total_char}] = {{'
        c_buf.append('};')
        h_buf.extend(
            ['', f'#define NUM_ZONE_NAMES {len(aliases)}', f'#define MAX_ZONE_NAME_LEN {max_char}', ''])
        h_buf.append(f'const unsigned char zone_names[{total_char}];')
