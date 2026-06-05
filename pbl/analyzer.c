#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "analyzer.h"
#include "metrics.h"
#include "timer.h"
#include "colors.h"

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "count_sort.h"

typedef struct {
    char name[50];
    double time;
    long long comparisons;
    long long swaps;
} AlgoResult;

const char* getAlgoName(int id) {
    switch (id) {
        case 1: return "Bubble Sort";
        case 2: return "Selection Sort";
        case 3: return "Insertion Sort";
        case 4: return "Merge Sort";
        case 5: return "Quick Sort";
        case 6: return "Count Sort";
        default: return "Unknown";
    }
}

void runAnalysis(int* arr, int arr_size, int* algos, int algos_count) {
    AlgoResult* results = (AlgoResult*)malloc(algos_count * sizeof(AlgoResult));
    int results_count = 0;

    for (int idx = 0; idx < algos_count; idx++) {
        int id = algos[idx];
        int* temp = (int*)malloc(arr_size * sizeof(int));
        memcpy(temp, arr, arr_size * sizeof(int));
        
        Metrics m = {0, 0};
        double t = 0;

        switch (id) {
            case 1:
                t = measureTime(bubbleSort, temp, arr_size, &m);
                break;
            case 2:
                t = measureTime(selectionSort, temp, arr_size, &m);
                break;
            case 3:
                t = measureTime(insertionSort, temp, arr_size, &m);
                break;
            case 4:
                t = measureTime(mergeSort, temp, arr_size, &m);
                break;
            case 5:
                t = measureTime(quickSort, temp, arr_size, &m);
                break;
            case 6:
                t = measureTime(countSort, temp, arr_size, &m);
                break;
            default:
                free(temp);
                continue;
        }

        strcpy(results[results_count].name, getAlgoName(id));
        results[results_count].time = t;
        results[results_count].comparisons = m.comparisons;
        results[results_count].swaps = m.swaps;
        results_count++;
        free(temp);
    }

    // Print table header
    printf("\n\n");
    COLOR_CYAN;
    printf("=====================================================================\n");
    printf("| %-18s | %-14s | %-14s | %-14s |\n", "Algorithm", "Time (ms)", "Comparisons", "Swaps");
    printf("=====================================================================\n");
    COLOR_RESET;


    for (int i = 0; i < results_count; i++) {
        AlgoResult* res = &results[i];

        if (i % 2 == 0) {
            COLOR_GREEN;
        } else {
            COLOR_YELLOW;
        }

        printf("| %-18s | %14.4f | %14lld | %14lld |\n",
               res->name, res->time, res->comparisons, res->swaps);
        COLOR_RESET;
    }

    // Print footer
    COLOR_CYAN;
    printf("=====================================================================\n");
    COLOR_RESET;

    // Print summary
    if (results_count > 0) {
        double minTime = results[0].time;
        double maxTime = results[0].time;
        int fastestIdx = 0, slowestIdx = 0;

        for (int i = 1; i < results_count; i++) {
            if (results[i].time < minTime) {
                minTime = results[i].time;
                fastestIdx = i;
            }
            if (results[i].time > maxTime) {
                maxTime = results[i].time;
                slowestIdx = i;
            }
        }

        printf("\n");
        COLOR_MAGENTA;
        printf("--- PERFORMANCE SUMMARY ---\n");
        COLOR_RESET;
        COLOR_GREEN;
        printf("FASTEST: ");
        COLOR_RESET;
        printf("%s (%.4f ms)\n", results[fastestIdx].name, results[fastestIdx].time);
        COLOR_RED;
        printf("SLOWEST: ");
        COLOR_RESET;
        printf("%s (%.4f ms)\n", results[slowestIdx].name, results[slowestIdx].time);
        COLOR_YELLOW;
        printf("DIFFERENCE: ");
        COLOR_RESET;
        printf("%.4f ms\n", maxTime - minTime);
    }

    printf("\n");
    COLOR_CYAN;
    printf("=====================================================================\n");
    COLOR_RESET;

    free(results);
}
