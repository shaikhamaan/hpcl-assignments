#include <omp.h>
#include <stdio.h>
#include <pthread.h>

void main()
{
    printf("Hello World\n");
#pragma omp parallel for

    for (int i = 0; i < 15; ++i)
    {
        printf("Hello from thread number %d\n", omp_get_thread_num());
    }
}
// gcc -fopenmp hello_world.c