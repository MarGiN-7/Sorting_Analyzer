#include "quick_sort.h"

int partitionQS(int* arr, int low, int high, Metrics* m) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        m->comparisons++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            m->swaps++;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    m->swaps++;
    return i + 1;
}


void quickSortHelper(int* arr, int low, int high, Metrics* m) {
    if (low < high) {
        int pi = partitionQS(arr, low, high, m);
        quickSortHelper(arr, low, pi - 1, m);
        quickSortHelper(arr, pi + 1, high, m);
    }
}


void quickSort(int* arr, int n, Metrics* m) {
    quickSortHelper(arr, 0, n - 1, m);
}
