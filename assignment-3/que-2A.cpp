#include <stdio.h>
#include <vector>
#include <omp.h>
using namespace std;
// #define SIZE 250
// #define SIZE 500
// #define SIZE 1000
#define SIZE 2000

// #define THREAD 2
// #define THREAD 4
#define THREAD 8

int main()
{
    // array declaration
    // int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
    vector<vector<int>> a(SIZE, vector<int>(SIZE));
    vector<vector<int>> b(SIZE, vector<int>(SIZE));
    vector<vector<int>> c(SIZE, vector<int>(SIZE));

    // time calculation
    double itime, ftime, exec_time;
    itime = omp_get_wtime();

    // serial region for initializing array
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            a[i][j] = j + 1;
            b[i][j] = j + 1;
        }
    }

    // parallel region for vector addition
    // setting num of threads
    omp_set_num_threads(THREAD);
#pragma omp parallel for collapse(2)
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // printing time
    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    printf("<--Parallel-->\nArray Size: %d\nNumber of Threads: %d", SIZE, THREAD);
    printf("\nTime taken is %f\n", exec_time);
    return 0;
}