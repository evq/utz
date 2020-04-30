#!/usr/bin/env python
""" Sample script to strip historical zones and rules

eV Quirk
"""

import click
import os

from utz import TimeZoneDatabase

DEFAULT_REGIONS = "africa,asia,australasia,backward,europe,northamerica,pacificnew,southamerica"
REGIONS = os.environ.get('TZ_REGIONS', DEFAULT_REGIONS).split(',')

CONTEXT_SETTINGS = dict(help_option_names=['-h', '--help'])


@click.command(context_settings=CONTEXT_SETTINGS)
@click.option('--dir', '-d', default=os.environ.get('TZ_DATA', 'vendor/tzdata'), help='Path to tzdata directory.')
@click.option('--build', '-b', default=os.environ.get('TZ_BUILD', 'build'), help='Path to build directory.')
def process(dir, build):
    """Sample script to strip historical timezones and rules"""
    for region in REGIONS:
        fn = os.path.join(dir, region)
        db = TimeZoneDatabase()
        with open(fn) as f:
            db.load(f)

        db.strip_historical()

        if not os.path.exists(build):
            os.mkdir(build)

        fn = os.path.join(build, region)
        with open(fn, 'w') as f:
            db.dump(f)


if __name__ == '__main__':
    process()
