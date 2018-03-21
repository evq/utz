#!/usr/bin/env python
""" Generate packed date constants

eV Quirk
"""

days_of_week = [
    'Monday',
    'Tuesday',
    'Wednesday',
    'Thursday',
    'Friday',
    'Saturday',
    'Sunday',
]
print("const char days_of_week[] = {")
dow_idx = []
for i in range(7):
    print("'%s','\\0'," % "', '".join([c for c in days_of_week[i]]))
    if i == 0:
        dow_idx.append(0)
    if i != 0:
        dow_idx.append(dow_idx[-1] + len(days_of_week[i-1]) + 1)
print("};")
print("")
print("const uint8_t days_of_week_idx[] = {%s};" % ", ".join(str(c) for c in dow_idx))

months_of_year = [
    'January',
    'February',
    'March',
    'April',
    'May',
    'June',
    'July',
    'August',
    'September',
    'October',
    'November',
    'December',
]
print("")
print("const char months_of_year[] = {")
moy_idx = []
for i in range(12):
    print("'%s','\\0'," % "', '".join([c for c in months_of_year[i]]))
    if i == 0:
        moy_idx.append(0)
    if i != 0:
        moy_idx.append(moy_idx[-1] + len(months_of_year[i-1]) + 1)
print("};")
print("")
print("const uint8_t months_of_year_idx[] = {%s};" % ", ".join(str(c) for c in moy_idx))
