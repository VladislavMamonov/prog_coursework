#include "AdditionalFunctions.h"
#include "sorting.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT uint32_t

int main(int argc, char* argv[])
{
    INT n;

    if (argc != 2) {
        printf("Usage:\nHeapSort or InsertionSort\n");
        return -1;
    }

    if (strcmp(argv[1], "InsertionSort") == 0 || strcmp(argv[1], "HeapSort") == 0) {
        printf("Input array size: ");
        scanf("%d", &n);

        INT* arr = NULL;

        arr = (INT*)malloc(n * sizeof(INT));
        if (arr == NULL) {
            printf("Memory allocation error\n");
            return -1;
        }

        for (INT i = 0; i < n; i++)
            arr[i] = getrand(0, 10000); /*Заполняем массив псевдослучайными числами*/

        if (strcmp(argv[1], "HeapSort") == 0)
            HeapSort(n, arr);
        if (strcmp(argv[1], "InsertionSort") == 0)
            InsertionSort(n, arr);

    } else {
        printf("Usage:\nHeapSort or InsertionSort\n");
        return -1;
    }

    return 0;
}