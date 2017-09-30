#!/usr/bin/env python
""" Create tz database links for major metropolian areas that don't exist in the IANA db

eV Quirk
"""

import unicodedata

from BeautifulSoup import BeautifulSoup
from geopy.geocoders import Nominatim
from tzwhere import tzwhere


def main():
    geocoder = Nominatim()
    tz = tzwhere.tzwhere()
    links = []

    with open('vendor/wikipedia/majormetros.html') as f:
        soup = BeautifulSoup(f)
        table = soup.find('table', {'class': "sortable wikitable"})
        for row in table.findAll('tr'):
            columns = row.findAll('td')
            if columns:
                metro = columns[1].find('a').text
                country = columns[2].find('a').text
                location = geocoder.geocode('%s, %s' % (metro, country))
                if not location:  # try just searching for just the metro
                    location = geocoder.geocode('%s' % metro)
                if location:
                    zone = tz.tzNameAt(location.latitude, location.longitude)
                    if zone:
                        metro = unicodedata.normalize('NFD', metro).encode('ascii', 'ignore')
                        metro = metro.replace(' ', '_')
                        if zone.split('/')[-1] not in metro:
                            alias = zone.split('/')[:-1]
                            alias.append(metro)
                            links.append(('Link', zone, '/'.join(alias)))
                        else:
                            print "%s, %s already present as %s" % (metro, country, zone)
                    else:
                        print "couldn't find zone for: %s, %s" % (metro, country)
                else:
                    print "couldn't find location for: %s, %s" % (metro, country)

    with open('majormetros', 'w') as f:
        f.write('\n'.join(['\t'.join(entry) for entry in links]))


if __name__ == '__main__':
    main()
