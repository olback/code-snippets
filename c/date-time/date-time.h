#include <inttypes.h>

#ifndef __DATE_TIME_H
#define __DATE_TIME_H

struct DateTime {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
};

struct DateTime date_time_get_compile_dt();
uint32_t date_time_to_epoch(struct DateTime*);
struct DateTime date_time_from_epoch(uint32_t);
void date_time_sprintf_time(char*, struct DateTime*);
void date_time_sprintf_date(char*, struct DateTime*);
void date_time_fancy_sprintf_date(char*, struct DateTime*);

#endif

