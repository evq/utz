/** @file example2.c
 *  @brief Example of how to get local time from utc time and set TZ env
 *
 *  @author Joshua Smith
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../utz.h"
#include "../zones.h"

static void copy_tm_to_udt(const struct tm *tm, udatetime_t *dt)
{
  dt->date.year = tm->tm_year - 100;
  dt->date.month = tm->tm_mon;
  dt->date.dayofmonth = tm->tm_mday;
  dt->date.dayofweek = tm->tm_wday;
  dt->time.hour = tm->tm_hour;
  dt->time.minute = tm->tm_min;
  dt->time.second = tm->tm_sec;
}

static time_t uoffset_to_seconds(const uoffset_t *offset)
{
  time_t seconds = offset->hours * 3600;
  seconds += (offset->hours >= 0 ? offset->minutes : -offset->minutes) * 60;
  return seconds;
}

int main()
{
  // 1. Get seconds after epoch
  time_t now = time(NULL);
  printf("UTC TIME:\t\t%s", asctime(gmtime(&now)));

  // 2. Get user selected zone
  uzone_t active_zone;
  get_zone_by_name("Halifax", &active_zone);

  // 3. Calculate standard time, pretending it's the new UTC
  time_t std_now = now + uoffset_to_seconds(&active_zone.offset);

  // 4. Get tm struct and convert it to the proper udatetime_t type;
  struct tm tm_std = *gmtime(&std_now);
  udatetime_t dt;
  copy_tm_to_udt(&tm_std, &dt);

  // 5. Get offset based on standard time
  uoffset_t offset;
  char c = get_current_offset(&active_zone, &dt, &offset);

  // Do what you want with the offset...

  time_t true_now = now + uoffset_to_seconds(&offset);
  printf("%s time:\t\t%s", active_zone.name, asctime(gmtime(&true_now)));
  printf(active_zone.abrev_formatter, c);
  printf("\n");

  return 0;
}
