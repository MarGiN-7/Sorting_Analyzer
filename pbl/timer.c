#include "timer.h"

#ifdef _WIN32
  #include <windows.h>

  double measureTime(SortFunction fn, int* arr, int n, Metrics* m) {
      LARGE_INTEGER freq, start, end;
      QueryPerformanceFrequency(&freq);
      QueryPerformanceCounter(&start);
      fn(arr, n, m);
      QueryPerformanceCounter(&end);
      return (double)(end.QuadPart - start.QuadPart) * 1000.0 / (double)freq.QuadPart;
  }

#else
  #include <time.h>

  double measureTime(SortFunction fn, int* arr, int n, Metrics* m) {
      struct timespec start, end;
      clock_gettime(CLOCK_MONOTONIC, &start);
      fn(arr, n, m);
      clock_gettime(CLOCK_MONOTONIC, &end);
      double elapsed = (end.tv_sec - start.tv_sec) * 1000.0
                     + (end.tv_nsec - start.tv_nsec) / 1e6;
      return elapsed;
  }

#endif
