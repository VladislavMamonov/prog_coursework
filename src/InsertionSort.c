#include "AdditionalFunctions.h"
#include "sorting.h"
#include <inttypes.h>
#include <stdio.h>
#include <sys/time.h>

#define INT uint32_t
#define n 50000

void InsertionSort(INT arr[n])
{
    double time;

    time = wtime(); /*Присваем переменной "time" текущее время в секундах*/

    for (INT i = 0; i < n; i++) {
        for (INT j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }

    for (INT i = 0; i < n; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    time = wtime() - time;
    printf("Work time: %f sec.\n", time); /*Записываем время работы функции*/
}