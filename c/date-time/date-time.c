#include <inttypes.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "date-time.h"

struct MonthLookup {
    char* month;
    uint8_t days;
};

static const struct MonthLookup month_lookup[12] = {
    { "Jan", 31 },
    { "Feb", 28 },
    { "Mar", 31 },
    { "Apr", 30 },
    { "May", 31 },
    { "Jun", 30 },
    { "Jul", 31 },
    { "Aug", 31 },
    { "Sep", 30 },
    { "Okt", 31 },
    { "Nov", 30 },
    { "Dec", 31 },
};

struct DateTime date_time_get_compile_dt() {
    struct DateTime dt;

    char subs[5] = { 0 };

    // Set year
    size_t space_counter = 0;
    for(size_t i = 0; i < 20; i++) {
        if (__DATE__[i] == 0x20) {
            space_counter++;
        }
        if (space_counter == 2) {
            memcpy(subs, &__DATE__[i], 5);
            dt.year = atoi(subs);
            break;
        }
    }

    // Set month
    memset(subs, 0, 5);
    memcpy(subs, &__DATE__[0], 3);
    for (size_t i = 0; i < 12; i++) {
        if (strcmp(subs, month_lookup[i].month) == 0) {
            dt.month = i + 1;
            break;
        }
    }

    // Set day
    space_counter = 0;
    size_t start, end = 0;
    for (size_t i = 0; i < 12; i++) {
        if (__DATE__[i] == 0x20) {
            space_counter++;
            if (space_counter == 1) {
                start = i;
            } else if (space_counter == 2) {
                end = i;
                break;
            }
        }
    }
    memcpy(subs, &__DATE__[start], end - start);
    dt.day = atoi(subs);

    // Set hours
    memset(subs, 0, 5);
    memcpy(subs, &__TIME__[0], 2);
    dt.hour = atoi(subs);

    // Set minutes
    memcpy(subs, &__TIME__[3], 2);
    dt.minute = atoi(subs);

    // Set seconds
    memcpy(subs, &__TIME__[6], 2);
    dt.second = atoi(subs);

    return dt;
}

uint32_t date_time_to_epoch(struct DateTime *dt) {
    uint32_t ts = 0;
    uint8_t non_leap_years = 0, leap_years = 0;

    // Count seconds up until this year
    for (size_t y = 1970; y < dt->year; y++) {
        (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) ? leap_years++ : non_leap_years++;
    }
    ts += ((non_leap_years * 365) + (leap_years * 366)) * 24 * 60 * 60;

    // Count seconds up to this month
    for (size_t m = 1; m < dt->month; m++) {
        if (m == 2 && (((dt->year % 4 == 0) && (dt->year % 100 != 0)) || (dt->year % 400 == 0))) {
            ts += (month_lookup[m - 1].days + 1) * 24 * 60 * 60;
        } else {
            ts += month_lookup[m - 1].days * 24 * 60 * 60;
        }
    }

    // Count seconds until yesterday
    ts += (dt->day - 1) * 24 * 60 * 60;

    // Count seconds passed today
    ts += (dt->hour * 60 * 60) + (dt->minute * 60) + dt->second;

    return ts;
}

struct DateTime date_time_from_epoch(uint32_t epoch) {

    uint32_t days = epoch / 60 / 60 / 24;
    uint32_t years = (float)days / 365.25;
    days -= (years * 365.25) - 1; // TODO: This is probably not correct

    struct DateTime dt = {
        .year = years + 1970,
        .month = 0,
        .day = 0,
        .hour = (epoch / 60 / 60) % 24,
        .minute = (epoch / 60) % 60,
        .second = epoch % 60
    };

    while (dt.month < 12) {
        dt.month++;
        uint8_t dim;
        if (dt.month == 2) {
            dim = 28 + (!(dt.year % 4)) + (!(dt.year % 100)) + (!(dt.year % 400));
        } else {
            dim = 30 + (dt.month + ((dt.month < 7))) % 2;
        }
        if (days > dim) {
            days = days - dim;
        } else {
            break;
        }
    }
    dt.day = days;

    return dt;
}

void date_time_sprintf_time(char* buf, struct DateTime *dt) {
    sprintf(buf, "%02u:%02u:%02u", dt->hour, dt->minute, dt->second);
    return;
}

void date_time_sprintf_date(char* buf, struct DateTime *dt) {
    sprintf(buf, "%u-%02u-%02u", dt->year, dt->month, dt->day);
    return;
}

void date_time_fancy_sprintf_date(char* buf, struct DateTime *dt) {
    sprintf(buf, "%s %d %d", month_lookup[dt->month - 1].month, dt->day, dt->year);
    return;
}

