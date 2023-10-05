#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void modifiedBubbleSort(int *arr, int n)
{
    int i, j;
    int swapped = 1;
    for (i = 0; i < n - 1 && swapped == 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
    }
}

int BinarySearch(int *a, int n, int data)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (data == a[mid])
        {
            return mid;
        }
        else if (data < a[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int binarySearchRecursive(int *arr, int left, int right, int target)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binarySearchRecursive(arr, left, mid - 1, target);
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
    return -1;
}

int main()
{
    int n, i, data;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the values in the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    modifiedBubbleSort(arr, n);
    printf("Enter the number you want to search: ");
    scanf("%d", &data);
    int search = binarySearchRecursive(arr, 0, n - 1, data);
    if (search == -1)
    {
        printf("Not present\n");
    }
    else
    {
        printf("The number is present at position %d\n", search + 1);
    }
    return 0;
}