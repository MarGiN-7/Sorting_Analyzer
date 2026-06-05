#ifndef TIMER_H
#define TIMER_H
#include "metrics.h"

typedef void (*SortFunction)(int*, int, Metrics*);

double measureTime(SortFunction fn, int* arr, int n, Metrics* m);

#endif
