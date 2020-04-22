#!/usr/bin/env python3
""" Micro timezone generator

eV Quirk
"""

import click
import os

from typing import List
from utz import TimeZoneDatabase

DEFAULT_REGIONS = "africa,asia,australasia,backward,europe,northamerica,pacificnew,southamerica"
CONTEXT_SETTINGS = dict(help_option_names=['-h', '--help'])
H_NAME = 'zones.h'
C_NAME = 'zones.c'


@click.command(context_settings=CONTEXT_SETTINGS)
@click.option('--dir', '-d', default=os.environ.get('UTZ_DATA_DIR', 'tzdata'), help='Path to tzdata dir.')
@click.option('--region', '-r', default=os.environ.get('UTZ_REGIONS', DEFAULT_REGIONS).split(','),
              help='Region files included from tzdata dir.', multiple=True)
@click.option('--include', '-i', default=filter(None, os.environ.get('UTZ_INCLUDES', '').split(',')),
              help='Additional tz database formated files included (not from tzdata dir).', multiple=True)
@click.option('--whitelist', '-w',
              default=os.environ.get('UTZ_WHITELIST', 'whitelist.txt'),
              help='Zone whitelist.')
def process(dir: str, region: List[str], include: List[str], whitelist: str):
    db = TimeZoneDatabase()

    for r in region:
        fn = os.path.join(dir, r)
        with open(fn) as f:
            db.load(f)

    for i in include:
        with open(i) as f:
            db.load(f)

    db.strip_historical()

    included_zones: List[str] = []
    if whitelist:
        with open(whitelist) as f:
            for zone in f:
                included_zones.append(zone.strip())

    c_buf, h_buf = db.pack(H_NAME, included_zones)
    with open(H_NAME, 'w') as hf:
        hf.write(h_buf)
    with open(C_NAME, 'w') as cf:
        cf.write(c_buf)


if __name__ == '__main__':
    process()
