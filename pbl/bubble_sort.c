/*
 * Bubble Sort - O(n^2) time, O(1) space
 * Simple comparison-based algorithm that repeatedly steps through the list,
 * compares adjacent elements and swaps them if they are in wrong order.
 */

#include "bubble_sort.h"

void bubbleSort(int* arr, int n, Metrics* m) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            m->comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                m->swaps++;
            }
        }
}
