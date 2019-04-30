#ifndef ADDITIONALFUNCTIONS_H
#define ADDITIONALFUNCTIONS_H

#include <inttypes.h>

#define INT uint32_t

double wtime();                //Функция возвращает текущее время в секундах
int getrand(int min, int max); //Функция, генерирующая псевдослучайные числа
void swap(INT* i, INT* j);

#endif