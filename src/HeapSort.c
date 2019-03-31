#include "AdditionalFunctions.h"
#include "sorting.h"
#include <inttypes.h>
#include <stdio.h>
#include <sys/time.h>

#define INT uint32_t
#define n 50000

void PyramidFormation(INT* arr, int i, int lower)
{
    int MaxChild;
    int flag = 0; /*flag - флаг, обозначающий факт, что куча отсортирована*/

    while ((i * 2 < lower) && (flag != 1)) { /*Цикл выполняется до тех пор, пока
                                                не достигнут нижнего ряда*/
        if (i * 2 == lower)
            MaxChild = i * 2; /*Если цикл достиг последнего ряда, то MaxChild
                                 присваивем левый потомок*/
        else if (arr[i * 2] > arr[i * 2 + 1])
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

void HeapSort(INT arr[n])
{
    double time;

    time = wtime(); /*Присваем переменной "time" текущее время в секундах*/

    for (int i = (n / 2) - 1; i >= 0; i--) {
        PyramidFormation(arr, i, n - 1); /*Формируем правую часть дерева*/
    }

    for (int i = n - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        PyramidFormation(arr, 0, i - 1); /*Формируем остальные элементы пирамиды*/
    }

    for (INT i = 0; i < n; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    time = wtime() - time;
    printf("Work time: %f sec.\n", time); /*Записываем время работы функции*/
}