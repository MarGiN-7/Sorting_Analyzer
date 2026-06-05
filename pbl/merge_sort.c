#include <stdlib.h>
#include "merge_sort.h"

void merge(int* arr, int l, int mid, int r, Metrics* met) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        met->comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        met->swaps++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    free(L);
    free(R);
}


void mergeSortHelper(int* arr, int l, int r, Metrics* m) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSortHelper(arr, l, mid, m);
        mergeSortHelper(arr, mid + 1, r, m);
        merge(arr, l, mid, r, m);
    }
}


void mergeSort(int* arr, int n, Metrics* m) {
    mergeSortHelper(arr, 0, n - 1, m);
}
