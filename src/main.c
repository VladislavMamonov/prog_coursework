#include "AdditionalFunctions.h"
#include "sorting.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define INT uint32_t
#define n 50000

int main()
{
    INT* arr = NULL;

    arr = (INT*)malloc(n * sizeof(INT));
    if (arr == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    for (INT i = 0; i < n; i++)
        arr[i] = getrand(0, 1000);

    printf("Press '1' for Insertion Sort\n");
    printf("Press '2' for Heap Sort\n");

    short choice;
    scanf("%hd", &choice);

    if (choice != 1 && choice != 2) {
        printf("Unknown sort\n");
    }

    if (choice == 1) {
        InsertionSort(arr);
    }

    if (choice == 2) {
        HeapSort(arr);
    }

    return 0;
}