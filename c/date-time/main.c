#include <stdio.h>
#include "date-time.h"

int main() {
    struct DateTime dt = date_time_get_compile_dt();

    char buf[50];

    date_time_fancy_sprintf_date(buf, &dt);
    printf("%s ", buf);

    date_time_sprintf_time(buf, &dt);
    printf("%s\n", buf);

    unsigned int epoch = date_time_to_epoch(&dt);

    struct DateTime dt_new = date_time_from_epoch(epoch);

    date_time_fancy_sprintf_date(buf, &dt_new);
    printf("%s ", buf);

    date_time_sprintf_time(buf, &dt_new);
    printf("%s\n", buf);

    return 0;
}

