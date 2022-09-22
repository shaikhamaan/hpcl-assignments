#include <omp.h>
#include <stdio.h>
#include <pthread.h>

void main()
{
    printf("Adding Vector into Scalar\n");
    int a1[] = {1, 2, 3, 4, 5};
    int answer = 0;

#pragma omp parallel for shared(answer)
    for (int i = 0; i < 5; i++)
    {
        answer += a1[i];
    }

    // serial
    printf("Answer %d \n", answer);
}

// gcc -fopenmp addingVectorScalar.c