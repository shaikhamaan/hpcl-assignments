#include <stdio.h>
#include <omp.h>

int sort(int arr[], int n)
{
    // int i, j;

    for (int i = 0; i < n - 1; i++)
    {
#pragma omp parallel for
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int sort_des(int arr[], int n)
{
    int i, j;

    for (i = 0; i < n; ++i)
    {
#pragma omp parallel for
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}

int main()
{
    // fill the code;
    int n;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    int i;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    // time calculation
    double itime, ftime, exec_time;
    itime = omp_get_wtime();

    sort(arr1, n);
    sort_des(arr2, n);

    int sum = 0;
#pragma omp parallel for reduction(+ \
                                   : sum)
    for (i = 0; i < n; i++)
    {
        sum = sum + (arr1[i] * arr2[i]);
    }

    // printing time
    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    printf("\nTime taken is %f\n", exec_time);

    printf("%d\n", sum);

    return 0;
}