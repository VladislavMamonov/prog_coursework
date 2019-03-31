#include "AdditionalFunctions.h"
#include <inttypes.h>
#include <stdlib.h>
#include <sys/time.h>

#define INT uint32_t
#define n 50000

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void swap(INT* i, INT* j)
{
    INT k;

    k = *i;
    *i = *j;
    *j = k;
}