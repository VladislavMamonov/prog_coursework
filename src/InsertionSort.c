#include "AdditionalFunctions.h"
#include "sorting.h"
#include <inttypes.h>
#include <stdio.h>
#include <sys/time.h>

#define INT uint32_t

void InsertionSort(INT n, INT mas[n])
{
    int i, j;
    double time;
    int key;
    FILE* InsertionSort = fopen("InsertionSort.dat", "w");

    time = wtime();

    for (i = 0; i < n; i++) {
        key = mas[i];
        j = i - 1;

        while (j > 0 && mas[j] > key) { //Пока предыдущий элемент больше текущего
            mas[j + 1] = mas[j]; //сдвигаем элементы массива до тех пор пока не найдём подходящее место
            j--;
        }

        mas[j + 1] = key;

        if (i % 50000 == 0) {
            double StepTime = wtime() - time;
            fprintf(InsertionSort, "%d\t%f\n", i, StepTime); /*Запись времени работы сортировки каждые 50 тыс. элементов*/
        }
    }

    for (i = 0; i < n; i++)
        printf("mas[%d] = %d\n", i, mas[i]);

    time = wtime() - time;
    printf("Work time: %f sec.\n", time);

    fclose(InsertionSort);
}
