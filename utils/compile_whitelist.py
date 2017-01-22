#!/usr/bin/env python
""" Small script to generate default zone whitelist from android and wikipedia info

Evey Quirk
"""

import xml.etree.ElementTree as ElementTree


def main():
    zones = []

    tree = ElementTree.parse('vendor/android/timezones.xml')
    zones.extend([child.attrib['id'] for child in tree.getroot()])

    with open('majormetros') as f:
        for line in f:
            zones.append(line.split('\t')[2].strip())

    with open('whitelist.txt', 'w') as f:
        f.write('\n'.join(sorted(zones)))


if __name__ == '__main__':
    main()
