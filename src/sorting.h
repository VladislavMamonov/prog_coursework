#include <inttypes.h>

#define INT uint32_t
#define n 50000

#ifndef SORTING_H
#define SORTING_H

void InsertionSort(INT arr[n]);
void SiftDown(INT* arr, int i, int lower);
void HeapSort(INT arr[n]);

#endif