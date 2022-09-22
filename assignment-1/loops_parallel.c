#include <omp.h>
#include <stdio.h>
#include <pthread.h>

void main()
{
    printf("Hello World\n");
#pragma omp parallel for
    for (int i = 0; i < 50; i++)
    {
        printf("Digit %d printed by thread %d\n", i, omp_get_thread_num());
    }
}
// gcc -fopenmp loops_parallel.c