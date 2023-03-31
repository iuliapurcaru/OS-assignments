#ifndef _TIME_H
#define _TIME_H   1

#include <internal/types.h>

typedef long time_t;

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *request, struct timespec *remaining);

#endif

