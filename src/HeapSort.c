#include "AdditionalFunctions.h"
#include "sorting.h"
#include <inttypes.h>
#include <stdio.h>
#include <sys/time.h>

#define INT uint32_t

void SiftDown(INT* arr, int i, int lower)
{
    int MaxChild;
    int flag = 0; /*flag - флаг, обозначающий факт, что куча отсортирована*/

    while ((i * 2 < lower) && (flag != 1)) { /*Цикл выполняется до тех пор, пока не достигнут нижнего ряда*/
        if (arr[i * 2] > arr[i * 2 + 1])
            MaxChild = i * 2;
        else /*Иначе MaxChild присваиваем больший потомок из двух*/
            MaxChild = i * 2 + 1;
        if (arr[i] < arr[MaxChild]) {
            swap(&arr[i], &arr[MaxChild]);
            i = MaxChild;
        } else
            flag = 1;
    }
}

void HeapSort(INT n, INT arr[n])
{
    double time;
    int i;

    time = wtime();

    for (int i = n - 1; i >= 0; i--) {
        SiftDown(arr, i, n - 1); /*Формируем кучу*/
    }

    for (i = n; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        SiftDown(arr, 0, i - 1); /*Формируем кучу после свапа элементов*/
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    time = wtime() - time;
    printf("Work time: %f sec.\n", time);
}