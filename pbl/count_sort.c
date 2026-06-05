#include <stdlib.h>
#include "count_sort.h"

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findMax(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int findMin(int* arr, int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

void countSort(int* arr, int n, Metrics* m) {
    if (n <= 0) return;

    int maxVal = findMax(arr, n);
    int minVal = findMin(arr, n);
    int range = maxVal - minVal + 1;

    int* count = (int*)calloc(range, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
        m->comparisons++;
    }

    // Prefix sum
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
        m->swaps++;
    }

    // Copy back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}
