#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int n)
{
    int bound = n;
    int t;
    do
    {
        t = 0;
        for (int i = 0; i < bound - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {

                arr[i] = arr[i] ^ arr[i + 1];
                arr[i + 1] = arr[i] ^ arr[i + 1];
                arr[i] = arr[i] ^ arr[i + 1];

                t = i;
            }
        }
        bound = t + 1;
    } while (t > 0);
}
int main()
{
    int n;
    printf("enter the size of the array:");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("entered array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    clock_t starttime = clock();
    bubbleSort(arr, n);
    clock_t endtime = clock();

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    double executionTime = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nExecution time: %lf seconds\n", executionTime);
    free(arr);
    return 0;
}