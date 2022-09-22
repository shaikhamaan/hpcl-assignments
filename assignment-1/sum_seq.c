#include <stdio.h>
#include <time.h>

void main()
{
    long long sum = 0;
    clock_t t;
    t = clock();

    for (long long i = 1; i < 200000000; i++)
    {
        sum += i * i;
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nTime taken is %f\n", time_taken);
    printf("Sum: %lld\n", sum);
}
