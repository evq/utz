/** @file utz.c
 *  @brief micro timezone library
 *
 *  @author eV
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utz.h"
#include "zones.h"

void bin_to_bcd(uint32_t* raw) {
  uint8_t* ptr = (uint8_t*) raw;
  for (uint8_t i = 0; i < 4; i++) {
    ptr[i] = ((ptr[i] / 10) << 4) | (ptr[i] % 10);
  }
}
void bcd_to_bin(uint32_t* raw) {
  uint8_t* ptr = (uint8_t*) raw;
  for (uint8_t i = 0; i < 4; i++) {
    ptr[i] = (ptr[i] & 0x0F) + ((ptr[i] >> 4) * 10);
  }
}

uint8_t dayofweek(uint8_t y, uint8_t m, uint8_t d) {
    static uint8_t t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    d = ((UYEAR_TO_YEAR(y) + (UYEAR_TO_YEAR(y)/4) - (UYEAR_TO_YEAR(y)/100) + UYEAR_OFFSET/400 + t[m-1] + d) % 7);
    if (d == 0) { return 7; } else { return d; }
}

uint8_t is_leap_year(uint8_t y) {
  if ((((UYEAR_TO_YEAR(y) % 4) == 0) && ((UYEAR_TO_YEAR(y) % 100) != 0)) || ((UYEAR_TO_YEAR(y) % 400) == 0)) {
    return true;
  }
  return false;
}

uint8_t days_in_month(uint8_t y, uint8_t m) {
  if (m == 2 && is_leap_year(y)) {
    return days_in_month_nonleap[m] + 1;
  } else {
    return days_in_month_nonleap[m];
  }
}

uint8_t next_dayofweek_offset(uint8_t dayofweek_of_cur, uint8_t dayofweek) {
  return (7 + dayofweek - dayofweek_of_cur) % 7;
}

uint8_t udatetime_eq(udatetime_t* dt1, udatetime_t* dt2) {
  return dt1->date.raw == dt2->date.raw && dt1->time.raw == dt2->time.raw;
}
uint8_t udatetime_lt(udatetime_t* dt1, udatetime_t* dt2) {
  return (dt1->date.raw < dt2->date.raw || 
         (dt1->date.raw == dt2->date.raw && dt1->time.raw < dt2->time.raw));
}
uint8_t udatetime_le(udatetime_t* dt1, udatetime_t* dt2) {
  return (dt1->date.raw < dt2->date.raw || 
         (dt1->date.raw == dt2->date.raw && dt1->time.raw <= dt2->time.raw));
}
uint8_t udatetime_gt(udatetime_t* dt1, udatetime_t* dt2) {
  return (dt1->date.raw > dt2->date.raw || 
         (dt1->date.raw == dt2->date.raw && dt1->time.raw > dt2->time.raw));
}
uint8_t udatetime_ge(udatetime_t* dt1, udatetime_t* dt2) {
  return (dt1->date.raw > dt2->date.raw || 
         (dt1->date.raw == dt2->date.raw && dt1->time.raw >= dt2->time.raw));
}

uint8_t next_packed_zone(char** list) {
  while(1) {
    if (*(*list) == '\0') {
      (*list)++;
      return (uint8_t) *(*list)++;
    }
    (*list)++;
  }
}

void unpack_rule(urule_packed_t* rule_in, uint8_t cur_year, urule_t* rule_out) {
  rule_out->date.year = cur_year;
  rule_out->date.month = rule_in->in_month;

  if (rule_in->on_dayofweek == 0) { // format is DOM e.g. 22
    rule_out->date.dayofmonth = rule_in->on_dayofmonth;
  } else if (rule_in->on_dayofmonth == 0) { // format is lastDOW e.g. lastSun
    uint8_t dayofweek_of_first_dayofmonth = dayofweek(cur_year, rule_in->in_month, 1);
    uint8_t first_dayofweek = next_dayofweek_offset(dayofweek_of_first_dayofmonth, rule_in->on_dayofweek);
    rule_out->date.dayofmonth = 1 + (7*3) + first_dayofweek;
    if (rule_out->date.dayofmonth + 7 <= days_in_month(cur_year, rule_in->in_month)) {
      rule_out->date.dayofmonth += 7;
    }
  } else { // format is DOW >= DOM e.g. Sun>=22
    uint8_t dayofweek_of_dayofmonth = dayofweek(cur_year, rule_in->in_month, rule_in->on_dayofmonth);
    rule_out->date.dayofmonth = rule_in->on_dayofmonth + next_dayofweek_offset(
      dayofweek_of_dayofmonth, 
      rule_in->on_dayofweek
    );
  }

  rule_out->time.hour = rule_in->at_hours;
  rule_out->time.minute = rule_in->at_inc_minutes * OFFSET_INCREMENT;

  rule_out->is_local_time = rule_in->at_is_local_time;
  switch(rule_in->letter) {
    case S:
      rule_out->letter = 's';
      break;
    case D:
      rule_out->letter = 'd';
      break;
    default:
      rule_out->letter = '-';
  }

  rule_out->offset_hours = rule_in->offset_hours;
}

// assumes no two rules are active on the same day
void sort_rules(urule_t* rules, uint8_t num_rules) {
  uint8_t swapped = true;
  urule_t tmp_current_rule;

  while(swapped) {
    swapped = false;
    for (uint8_t i = 1; i < num_rules; i++) {
      if (rules[i-1].date.raw > rules[i].date.raw) {
        tmp_current_rule = rules[i-1];
        rules[i-1] = rules[i];
        rules[i] = tmp_current_rule;
        swapped = true;
      }
    }
  }
}

void unpack_rules(urule_packed_t* rules_in, uint8_t num_rules, uint8_t cur_year, urule_t* rules_out) {
  uint8_t current_rule_count = 0;

  // First lets find the "last" rule of the previous year, for simplification 
  // this assumes that multiple rules don't apply to the same month
  int8_t l = 0;
  for (uint8_t i = 1; i < num_rules; i++) {
    if (cur_year - 1 >= rules_in[i].from_year && cur_year - 1 <= rules_in[i].to_year) {
      if (rules_in[i].in_month > rules_in[l].in_month) {
        l = i;
      }
    }
  }
  unpack_rule(&rules_in[l], cur_year, &rules_out[current_rule_count]);
  // We override the "last" rule time of effect to be the start of the current year
  rules_out[current_rule_count].date.raw = 0;
  rules_out[current_rule_count].date.year = cur_year;
  rules_out[current_rule_count].date.month = 1;
  rules_out[current_rule_count].date.dayofmonth = 1;
  rules_out[current_rule_count].time.raw = 0;
  current_rule_count++;

  for (uint8_t i = 0; i < num_rules && current_rule_count < MAX_CURRENT_RULES; i++) {
    if (cur_year >= rules_in[i].from_year && cur_year <= rules_in[i].to_year) {
      unpack_rule(&rules_in[i], cur_year, &rules_out[current_rule_count++]);
    }
  }

  sort_rules(rules_out, current_rule_count);
}

urule_t* get_active_rule(urule_t* rules, udatetime_t* datetime) {
  for (uint8_t i = 1; i < MAX_CURRENT_RULES; i++) {
    if (!RULE_IS_VALID(rules[i]) || udatetime_lt(datetime, &(rules[i].datetime))) {
      return &rules[i-1];
    }
  }
  return &rules[MAX_CURRENT_RULES-1];
}

uoffset_t get_current_offset(uzone_t* zone, udatetime_t* datetime) {
  if (last_zone != zone->src || last_year != datetime->date.year) {
    unpack_rules(zone->rules, zone->rules_len, datetime->date.year, cached_rules);
    last_zone = zone->src;
    last_year = datetime->date.year;
  }

  uoffset_t offset = zone->offset;
  offset.hours += get_active_rule(cached_rules, datetime)->offset_hours;
  return offset;
}

void unpack_zone(uzone_packed_t* zone_in, char* name, uzone_t* zone_out) {
  zone_out->src = zone_in;
  strncpy(zone_out->name, name, MAX_ZONE_NAME_LEN);

  zone_out->offset.minutes = (zone_in->offset_inc_minutes % (60 / OFFSET_INCREMENT)) * OFFSET_INCREMENT;
  zone_out->offset.hours = zone_in->offset_inc_minutes / (60 / OFFSET_INCREMENT);
  zone_out->rules = &zone_rules[zone_in->rules_idx];
  zone_out->rules_len = zone_in->rules_len;
  strncpy(zone_out->abrev_formatter, zone_in->abrev_formatter, MAX_ABREV_FORMATTER_LEN);
}
