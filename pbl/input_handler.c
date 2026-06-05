#include <stdio.h>
#include <stdlib.h>

int getInputMethod() {
    int ch;
    printf("1.AUTO GENERATE\n2. MANUAL INPUT\nChoice: ");
    scanf("%d", &ch);
    return ch;
}

int getArraySize() {
    int n;
    printf("Array size: ");
    scanf("%d", &n);
    return n;
}

int getDataType() {
    int t;
    printf("1.RANDOM\n2.SORTED\n3.REVERSE SORTED\nChoice: ");
    scanf("%d", &t);
    return t;
}

int* getManualArray(int* size) {
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    *size = n;
    return a;
}

int* getAlgorithmChoices(int* count) {
    int* c = (int*)malloc(10 * sizeof(int));
    int x;
    int idx = 0;
    printf("1.BUBBLE SORT\n2.SELECTION SORT\n3.INSERTION SORT\n4.MERGE SORT\n5.QUICK SORT\n6.COUNT SORT\n(press 0 to stop)\n");
    while (1) {
        scanf("%d", &x);
        if (x == 0) break;
        c[idx++] = x;
    }
    *count = idx;
    return c;
}

