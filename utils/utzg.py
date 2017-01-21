#!/usr/bin/env python
""" Micro timezone generator

Evey Quirk
"""

import click
import os

from datetime import date

from tzlib import TimeZoneDatabase

CURRENT_YEAR = date.today().year
LIFETIME_YEARS = 10  # Assume we don't care about rules starting more than 10 years in the future

DEFAULT_REGIONS = "africa,asia,australasia,backward,europe,northamerica,pacificnew,southamerica"
REGIONS = os.environ.get('TZ_REGIONS', DEFAULT_REGIONS).split(',')

CONTEXT_SETTINGS = dict(help_option_names=['-h', '--help'])

@click.command(context_settings=CONTEXT_SETTINGS)
@click.option('--dir', '-d', default=os.environ.get('TZ_DATA', 'tzdata'), help='Path to tzdata directory.')
def process(dir):
    db = TimeZoneDatabase()
    for region in REGIONS:
        fn = os.path.join(dir, region)
        with open(fn) as f:
            db.load(f)
    db.strip_historical()
    with open('utz_zones.h', 'w') as f:
        f.write(db.pack())

if __name__ == '__main__':
    process()
