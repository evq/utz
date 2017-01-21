#!/usr/bin/env python
""" Sample script to strip historical zones and rules

Evey Quirk
"""

import click
import os

from tzlib import TimeZoneDatabase

DEFAULT_REGIONS = "africa,asia,australasia,backward,europe,northamerica,pacificnew,southamerica"
REGIONS = os.environ.get('TZ_REGIONS', DEFAULT_REGIONS).split(',')

CONTEXT_SETTINGS = dict(help_option_names=['-h', '--help'])


@click.command(context_settings=CONTEXT_SETTINGS)
@click.option('--dir', '-d', default=os.environ.get('TZ_DATA', 'tzdata'), help='Path to tzdata directory.')
@click.option('--out-dir', '-o', default=os.environ.get('TZ_BUILD', 'build'), help='Path to output directory.')
def process(dir, out_dir):
    """Sample script to strip historical timezones and rules"""
    for region in REGIONS:
        fn = os.path.join(dir, region)
        db = TimeZoneDatabase()
        with open(fn) as f:
            db.load(f)

        db.strip_historical()

        if not os.path.exists(out_dir):
            os.mkdir(out_dir)

        fn = os.path.join(out_dir, region)
        with open(fn, 'w') as f:
            db.dump(f)


if __name__ == '__main__':
    process()
