#include <stdio.h>
#include <vector>
#include <time.h>
using namespace std;
// #define SIZE 250
// #define SIZE 500
// #define SIZE 1000
#define SIZE 2000

int main()
{
    // array declaration
    // int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
    vector<vector<int>> a(SIZE, vector<int>(SIZE));
    vector<vector<int>> b(SIZE, vector<int>(SIZE));
    vector<vector<int>> c(SIZE, vector<int>(SIZE));

    // time calculation
    clock_t t;
    t = clock();

    // serial region for initializing array
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            a[i][j] = j + 1;
            b[i][j] = j + 1;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // printing time
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("<--Serial-->\nArray Size: %d", SIZE);
    printf("\nTime taken is %f\n", time_taken);

    return 0;
}