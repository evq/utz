#!/usr/bin/env python3
""" Create tz database links for major metropolian areas that don't exist in the IANA db

eV Quirk
"""

import unicodedata

from bs4 import BeautifulSoup
from geopy.geocoders import Nominatim
from tzwhere import tzwhere


def main():
    geocoder = Nominatim(user_agent="utz", timeout=30)
    tz = tzwhere.tzwhere()
    links = []

    with open('vendor/wikipedia/majorcities.html') as f:
        soup = BeautifulSoup(f, features="html.parser")
        table = soup.find(
            'table', {'class': "sortable wikitable mw-datatable"})
        for row in table.findAll('tr'):
            columns = row.findAll('td')
            if columns:
                city = columns[0].find('a').text
                country = columns[1].findAll('a')[1].text
                location = geocoder.geocode(f"{city}, {country}")
                if not location:  # try just searching for just the city
                    location = geocoder.geocode(city)
                if location:
                    zone = tz.tzNameAt(location.latitude, location.longitude)
                    if zone:
                        city = unicodedata.normalize('NFD', city).encode(
                            'ascii', 'ignore').decode('ascii')
                        city = city.replace(' ', '_')
                        if zone.split('/')[-1] not in city:
                            alias = zone.split('/')[:-1]
                            alias.append(city)
                            links.append(('Link', zone, '/'.join(alias)))
                        else:
                            print(f"{city}, {country} already present as {zone}")
                    else:
                        print(f"couldn't find zone for: {city}, {country}")
                else:
                    print(f"couldn't find location for: {city}, {country}")

    with open('majorcities', 'w') as f:
        f.write('\n'.join(['\t'.join(entry) for entry in links]))


if __name__ == '__main__':
    main()
