#!/usr/bin/env python
""" Small script to generate default zone whitelist from android and wikipedia info

Evey Quirk
"""

import xml.etree.ElementTree as ElementTree


def main():
    zones = set()

    tree = ElementTree.parse('vendor/android/timezones.xml')
    zones.update([child.attrib['id'] for child in tree.getroot()])

    with open('majormetros') as f:
        for line in f:
            zones.add(line.split('\t')[1].strip())
            zones.add(line.split('\t')[2].strip())

    with open('whitelist.txt', 'w') as f:
        f.write('\n'.join(sorted(zones)))


if __name__ == '__main__':
    main()
