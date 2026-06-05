#include <stdlib.h>
#include <time.h>

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareIntsDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int* generateData(int n, int type) {
    int* a = (int*)malloc(n * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000000000;  // random number

    if (type == 2) 
        qsort(a, n, sizeof(int), compareInts);
    else if (type == 3) 
        qsort(a, n, sizeof(int), compareIntsDesc);

    return a;
}
