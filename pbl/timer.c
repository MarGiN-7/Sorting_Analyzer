#include <time.h>
#include "timer.h"

double measureTime(SortFunction fn, int* arr, int n, Metrics* m) {
    clock_t start = clock();
    fn(arr, n, m);
    clock_t end = clock();
    double elapsed = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0; 
    return elapsed;
}
