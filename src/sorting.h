#ifndef SORTING_H
#define SORTING_H

#include <inttypes.h>

#define INT uint32_t

void InsertionSort(INT n, INT arr[n]);
void SiftDown(INT* arr, int i, int lower);
void HeapSort(INT n, INT arr[n]);

#endif