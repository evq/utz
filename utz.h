/** @file utz.h
 *  @brief micro timezone library header
 *
 *  @author eV
 */

#ifndef _UTZ_H
#define _UTZ_H

#include <stdint.h>

#define UTRUE 1
#define UFALSE 0

#define UYEAR_OFFSET 2000
#define UYEAR_FROM_YEAR(y) (y - UYEAR_OFFSET)
#define UYEAR_TO_YEAR(y) (y + UYEAR_OFFSET)

#define OFFSET_INCREMENT 15 // Minutes

#define MAX_ABREV_FORMATTER_LEN 5
#define MAX_ZONE_NAME_LEN 16
#define MAX_CURRENT_RULES 4 + 1 // Fuck Morocco

#define RULE_IS_VALID(r) ((r).letter != 0)

#define S 1
#define D 2

/**************************************************************************/
/*                          struct definitions                            */
/**************************************************************************/

// reverse for big endian comparisons via raw?
/** @struct utime_t
 *  @brief time type
 *
 *  @var utime_t::second 0-59 or 0-0x59 in bcd mode
 *  @var utime_t::minute 0-59 or 0-0x59 in bcd mode
 *  @var utime_t::hour 0-23 or 0-0x23 in bcd mode
 *  @var utime_t::padding unused space to pad to 4 bytes
 *  @var utime_t::raw for comparisons and conversions
 */
typedef struct utime_t {
  union {
    struct {
      uint8_t second;
      uint8_t minute;
      uint8_t hour;
      uint8_t padding;
    };
    uint32_t raw;
  };
} utime_t;

// reverse for big endian comparisons via raw?
/** @struct udate_t
 *  @brief date type
 *
 *  @var udate_t::dayofweek day of week (monday = 1, sunday = 7)
 *  @var udate_t::dayofmonth 01-31 or 0x01-0x31 in bcd mode
 *  @var udate_t::month 01-12 or 0x01-0x12 in bcd mode
 *  @var udate_t::year 00-99 or 0x00-0x99 in bcd mode
 *  @var udate_t::padding unused space to pad to 4 bytes
 *  @var udate_t::raw for comparisons and conversions
 */
typedef struct udate_t {
  uint8_t dayofweek;
  union {
    struct {
      uint8_t dayofmonth; // 01-31 or 0x01-0x31 in bcd mode
      uint8_t month;      // 01-12 or 0x01-0x12 in bcd mode
      uint8_t year;       // 00-99 or 0x00-0x99 in bcd mode (offset 2000 ???)
      uint8_t padding;    // unused space to pad to 4 bytes
    };
    uint32_t raw;         // raw field for comparisons and conversions
  };
} udate_t;


/** @brief datetime type */
typedef struct udatetime_t {
  utime_t time;
  udate_t date;
} udatetime_t;

/** @brief timezone offset type */
typedef struct uoffset_t {
  uint8_t minutes; // 0 to 59
  int8_t hours; // -12 to +12
} uoffset_t;

/** @struct uzone_packed_t
 *  @brief packed timezone type
 *
 *  @var uzone_packed_t::offset_inc_minutes signed minutes in increments of OFFSET_INCREMENT
 *  @var uzone_packed_t::rules_idx index into rules array for start of corresponding rules
 *  @var uzone_packed_t::rules_len number of rule entries
 *  @var uzone_packed_t::abrev_formatter abreviation formatter
 */
typedef struct uzone_packed_t {
  int8_t offset_inc_minutes;
  uint8_t rules_idx;
  uint8_t rules_len;
  char abrev_formatter[MAX_ABREV_FORMATTER_LEN];
} uzone_packed_t;

/** @struct urule_packed_t
 *  @brief packed rule type, rules for daylight savings time
 *
 * There are 3 possible formats for on - the specifier for the day when the rule takes effect:
 * 1) the default format is "dayOfWeek >= dayOfMonth"
 * 2) unless on_dayofweek is 0, in which case the format is "dayOfMonth"
 * 3) unless on_dayofmonth is 0, in which case the format is "last dayOfWeek"
 *
 *  @var urule_packed_t::from_year years since 2000
 *  @var urule_packed_t::to_year years since 2000
 *  @var urule_packed_t::on_dayofweek day of week (monday = 1, sunday = 7) 
 *  @var urule_packed_t::on_dayofmonth day of month 
 *  @var urule_packed_t::at_is_local_time is time of day in local time, if not utc
 *  @var urule_packed_t::at_hours time of day, hours
 *  @var urule_packed_t::at_inc_minutes time of day, minutes, in OFFSET_INCREMENT minute increments
 *  @var urule_packed_t::letter (-,S,D) sorry Troll, Antarctica
 *  @var urule_packed_t::in_month month (1-12)
 *  @var urule_packed_t::offset_hours (0-3)
 */
typedef struct urule_packed_t {
  uint8_t from_year;
  uint8_t to_year;
  uint8_t on_dayofweek:3;
  uint8_t on_dayofmonth:5;
  uint8_t at_is_local_time:1;
  uint8_t at_hours:5;
  uint8_t at_inc_minutes:2;
  uint8_t letter:2;
  uint8_t in_month:4;
  uint8_t offset_hours:2;
} urule_packed_t;

/** @brief unpacked zone type */
typedef struct uzone_t {
  char name[MAX_ZONE_NAME_LEN+1];
  uoffset_t offset;
  const urule_packed_t* rules;
  uint8_t rules_len;
  char abrev_formatter[MAX_ABREV_FORMATTER_LEN+1];
  const uzone_packed_t* src;
} uzone_t;

/** @brief unpacked rule type, rules for daylight savings time */
typedef struct urule_t {
  union {
    udatetime_t datetime;
    struct {
      utime_t time;
      udate_t date;
    };
  };
  uint8_t is_local_time;
  char letter;
  uint8_t offset_hours;
} urule_t;

/**************************************************************************/
/*                                globals                                 */
/**************************************************************************/

/** @brief lookup table for the number of days in a given month when the year is not a leap year */
static const uint8_t days_in_month_nonleap[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/** @brief lookup table name of the days of week */
static const char* days_of_week[8] = {"0", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

static const uint8_t dayofweek_table[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

/** @brief cached rules for the zone and year from the last call of get_current_offset */
static urule_t cached_rules[MAX_CURRENT_RULES];

/** @brief the zone pointer from the last call of get_current_offset */
static const uzone_packed_t* last_zone;

/** @brief the year (1 <= y <= 255 (2001 - 2255)) from the last call of get_current_offset */
static uint8_t last_year;

/**************************************************************************/
/*                         datetime functions                             */
/**************************************************************************/

/** @brief convert a binary formatted udate_t or utime_t to bcd format via a pointer to the raw field
 *
 *  @param pointer to the raw field of a udate_t or utime_t
 *  @return void
 */
void bin_to_bcd(uint32_t* raw);

/** @brief convert a bcd formatted udate_t or utime_t to binary format via a pointer to the raw field
 *
 *  @param pointer to the raw field of a udate_t or utime_t
 *  @return void
 */
void bcd_to_bin(uint32_t* raw);

/** @brief returns the day of the week for the given year/month/day
 *
 *  @param y year: 1 <= y <= 255 (2001 - 2255)
 *  @param m month: 1 <= m <= 12
 *  @param d day: 1 <= d <= 31
 *  @return day of week (Monday = 1, Sunday = 7)
 */
uint8_t dayofweek(uint8_t y, uint8_t m, uint8_t d);

/** @brief returns true if the year is a leap year
 *
 *  @param y year: 1 <= y <= 255 (2001 - 2255)
 *  @brief true if the year is a leap year
 */
uint8_t is_leap_year(uint8_t y);

/** @brief returns the number of days in the year/month, taking leap years into account
 *
 *  @param y year: 1 <= y <= 255 (2001 - 2255)
 *  @param m month: 1 <= m <= 12
 *  @return number of days
 */
uint8_t days_in_month(uint8_t y, uint8_t m);

/** @brief returns days needed to get from the "current" day to the desired day of the week.
 *
 *  @param dayofweek_of_cur the "current" day of the week: 1 <= dayofweek_of_cur <= 7 (Monday = 1, Sunday = 7)
 *  @param dayofweek the desired day of the week: 1 <= dayofweek <= 7 (Monday = 1, Sunday = 7)
 *  @return number of days
 */
uint8_t next_dayofweek_offset(uint8_t dayofweek_of_cur, uint8_t dayofweek);

/** @brief returns *dt1 == *dt2
 *
 *  @param dt1 pointer to the first datetime
 *  @param dt1 pointer to the second datetime
 *  @return *dt1 == *dt2
 */
uint8_t udatetime_eq(udatetime_t* dt1, udatetime_t* dt2);

/** @brief returns *dt1 < *dt2
 *
 *  @param dt1 pointer to the first datetime
 *  @param dt1 pointer to the second datetime
 *  @return *dt1 < *dt2
 */
uint8_t udatetime_lt(udatetime_t* dt1, udatetime_t* dt2);

/** @brief returns *dt1 <= *dt2
 *
 *  @param dt1 pointer to the first datetime
 *  @param dt1 pointer to the second datetime
 *  @return *dt1 <= *dt2
 */
uint8_t udatetime_le(udatetime_t* dt1, udatetime_t* dt2);

/** @brief returns *dt1 > *dt2
 *
 *  @param dt1 pointer to the first datetime
 *  @param dt1 pointer to the second datetime
 *  @return *dt1 > *dt2
 */
uint8_t udatetime_gt(udatetime_t* dt1, udatetime_t* dt2);

/** @brief returns *dt1 >= *dt2
 *
 *  @param dt1 pointer to the first datetime
 *  @param dt1 pointer to the second datetime
 *  @return *dt1 >= *dt2
 */
uint8_t udatetime_ge(udatetime_t* dt1, udatetime_t* dt2);

/**************************************************************************/
/*                         zone rule functions                            */
/**************************************************************************/

/** @brief unpack rule
 *
 *  @param rule_in pointer to packed rule
 *  @param cur_year year: 1 <= y <= 255 (2001 - 2255)
 *  @param rule_out pointer for the output unpacked rule
 *  @return void
 */
void unpack_rule(const urule_packed_t* rule_in, uint8_t cur_year, urule_t* rule_out);

/** @brief unpack rules that are active in the current year
 *
 *  Note this assumes no two rules are active on the same day
 *
 *  @param rules_in pointer to packed rules
 *  @param num_rules the number of rules in the array
 *  @param cur_year year: 1 <= y <= 255 (2001 - 2255)
 *  @param rules_out pointer for the output unpacked rules
 *  @return void
 */
void unpack_rules(const urule_packed_t* rules_in, uint8_t num_rules, uint8_t cur_year, urule_t* rules_out);

/** @brief get the rule that applies at datetime
 *
 *  @param rules pointer to rules
 *  @param datetime the datetime to check rules for
 *  @return a pointer the the rule that applies
 */
urule_t* get_active_rule(urule_t* rules, udatetime_t* datetime);

/** @brief get the offset for zone at datetime, taking into account daylight savings time rules
 *
 *  @param zone pointer to zone
 *  @param datetime the datetime to check rules for
 *  @param offset offset for zone at datetime
 *  @return abbreviation letter
 */
char get_current_offset(uzone_t* zone, udatetime_t* datetime, uoffset_t* offset);

/** @brief unpack timezone
 *
 *  @param name the name of the timezone
 *  @param zone_in pointer to input packed zone
 *  @param zone_in pointer to output unpacked zone
 *  @return void
 */
void unpack_zone(const uzone_packed_t* zone_in, char* name, uzone_t* zone_out);

/** @brief advance pointer to list of zone names and returns the prev index into the zone definitions array
 *
 *  @param list pointer to pointer into zone names list
 *  @return index into the zone definitions array for the zone name before advancement
 */
uint8_t next_packed_zone(const char** list);

/** @brief lookup a zone via zone_names
 *
 *  @param name the name of the zone to find
 *  @param zone_out pointer for zone found
 *  @return void
 */
void get_zone_by_name(char* name, uzone_t* zone_out);

#endif /* _UTZ_H */
