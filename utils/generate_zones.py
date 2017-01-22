#!/usr/bin/env python
""" Micro timezone generator

Evey Quirk
"""

import click
import os

from utz import TimeZoneDatabase

DEFAULT_REGIONS = "africa,asia,australasia,backward,europe,northamerica,pacificnew,southamerica"
CONTEXT_SETTINGS = dict(help_option_names=['-h', '--help'])


@click.command(context_settings=CONTEXT_SETTINGS)
@click.option('--dir', '-d', default=os.environ.get('UTZ_DATA_DIR', 'tzdata'), help='Path to tzdata dir.')
@click.option('--region', '-r', default=os.environ.get('UTZ_REGIONS', DEFAULT_REGIONS).split(','),
              help='Region files included from tzdata dir.', multiple=True)
@click.option('--include', '-i', default=filter(None, os.environ.get('UTZ_INCLUDES', '').split(',')),
              help='Additional tz database formated files included (not from tzdata dir).', multiple=True)
@click.option('--out-file', '-O', default='zones.h', help='Output filename.')
@click.option('--whitelist', '-w',
              default=os.environ.get('UTZ_WHITELIST', 'whitelist.txt'),
              help='Zone whitelist.')
def process(dir, region, include, out_file, whitelist):
    db = TimeZoneDatabase()

    for r in region:
        fn = os.path.join(dir, r)
        with open(fn) as f:
            db.load(f)

    for i in include:
        with open(i) as f:
            db.load(f)

    db.strip_historical()

    included_zones = []
    if whitelist:
        with open(whitelist) as f:
            for zone in f:
                included_zones.append(zone.strip())

    out_dir = os.path.dirname(out_file)
    if out_dir and not os.path.exists(out_dir):
        os.mkdir(out_dir)

    with open(out_file, 'w') as f:
        f.write(db.pack(os.path.basename(out_file), included_zones))


if __name__ == '__main__':
    process()
