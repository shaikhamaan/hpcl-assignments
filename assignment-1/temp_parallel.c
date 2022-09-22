#include <omp.h>
#include <stdio.h>
void main(int argc, char *argv[])
{
/* sequential code */
#pragma omp parallel
    {
        printf("I am a parallel region.\n");
    }
    /* sequential code */
}