/** @file utz.h
 *  @brief Micro timezone struct definitions
 *
 *  @author Evey Quirk
 */
#ifndef _UTZ_H
#define _UTZ_H

typedef struct uzone_t {
   int8_t utc_offset_M; // signed 15 minute increments
   uint8_t rules_idx;  // index into rules array for start of corresponding rules
   uint8_t rules_len;  // number of rule entries
   char abrev[4];      // abreviation formatter
} uzone_t;

typedef struct urule_t {
   uint8_t from_Y;   // years since 1970
   uint8_t to_Y;     // years since 1970

   // assume the default format is "dayOfWeek >= dayOfMonth"
   uint8_t on_u:3;     // day of week (monday = 1) unless 0, in which case assume format is "dayOfMonth"
   uint8_t on_d:5;     // day of month unless 0, in which case assume format is "last dayOfWeek"

   uint8_t at_z:1;     // time of day, zone (UTC, LOCAL)
   uint8_t at_H:5;     // time of day, hours
   uint8_t at_M:2;     // time of day, minutes, in 15 minute increments

   uint8_t letter:2;      // (-,S,D)          sorry Troll, Antarctica
   uint8_t in_m:4;     // month
   uint8_t offset_H:2; // (0-3)
} urule_t;

#define S 1
#define D 2

#endif /* _UTZ_H */
