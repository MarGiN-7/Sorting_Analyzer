#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_handler.h"
#include "data_generator.h"
#include "analyzer.h"
#include "colors.h"

void printTitle() {
    COLOR_CYAN;
    printf("====================================================\n");
    printf("                                                    \n");
    printf("   SORTING PERFORMANCE ANALYZER                    \n");
    printf("                                                    \n");
    printf("====================================================\n");
    COLOR_RESET;
}

int main() {
    printTitle();

    int* arr = NULL;
    int arr_size = 0;
    int method = getInputMethod();

    printf("\n");
    COLOR_YELLOW;
    printf("-----------------------------------------------------\n");
    COLOR_RESET;

    if (method == 1) {
        COLOR_GREEN;
        printf("[OK] Data Generation Mode Selected\n");
        COLOR_RESET;
        int n = getArraySize();
        int type = getDataType();
        arr = generateData(n, type);
        arr_size = n;
        COLOR_GREEN;
        printf("[OK] Data generated successfully.\n");
        COLOR_RESET;
        COLOR_CYAN;
        printf("\nGenerated Array (%d elements):\n", arr_size);
        COLOR_RESET;
        COLOR_YELLOW;
        printf("[ ");
        for (int i = 0; i < arr_size && i < 20; i++) {
            printf("%d ", arr[i]);
        }
        if (arr_size > 20) printf("... ");
        printf("]\n");
        COLOR_RESET;
    }
    else if (method == 2) {
        COLOR_GREEN;
        printf("[OK] Manual Input Mode Selected\n");
        COLOR_RESET;
        arr = getManualArray(&arr_size);
        COLOR_GREEN;
        printf("[OK] Array captured successfully.\n");
        COLOR_RESET;
        COLOR_CYAN;
        printf("\nInput Array:\n");
        COLOR_RESET;
        COLOR_YELLOW;
        printf("[ ");
        for (int i = 0; i < arr_size; i++) {
            printf("%d ", arr[i]);
        }
        printf("]\n");
        COLOR_RESET;
    }
    else {
        COLOR_RED;
        printf("[ERROR] Invalid choice. Exiting...\n");
        COLOR_RESET;
        return 0;
    }

    printf("\n");
    COLOR_YELLOW;
    printf("-----------------------------------------------------\n");
    COLOR_RESET;

    int* algos = NULL;
    int algos_count = 0;
    algos = getAlgorithmChoices(&algos_count);

    if (algos_count == 0) {
        COLOR_RED;
        printf("[ERROR] No algorithms selected. Exiting...\n");
        COLOR_RESET;
        free(arr);
        free(algos);
        return 0;
    }

    runAnalysis(arr, arr_size, algos, algos_count);

    printf("\n");
    COLOR_MAGENTA;
    printf("====================================================\n");
    printf("                                                    \n");
    printf("          ANALYSIS COMPLETE                         \n");
    printf("                                                    \n");
    printf("====================================================\n");
    COLOR_RESET;

    free(arr);
    free(algos);

    
    return 0;
}
