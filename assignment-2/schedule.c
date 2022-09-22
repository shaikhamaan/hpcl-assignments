#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
    float b[5], y[5];
    float a[] = {5, 8, 9, 1, 6};
    float z[] = {7, 9, 16, 8498, 588};

    int i;

#pragma omp parallel
    {
#pragma omp for
        for (i = 1; i < 5; i++)
            b[i] = (a[i] + a[i - 1]) / 2;

#pragma omp for
        for (i = 0; i < 5; i++)
            y[i] = sqrt(z[i]);
    }

    printf("B\n");
    for (i = 0; i < 5; i++)
    {
        printf("B%d: %f\n", i + 1, b[i]);
    }

    printf("Y\n");
    for (i = 0; i < 5; i++)
    {
        printf("Y%d: %f\n", i + 1, b[i]);
    }

    return 0;
}