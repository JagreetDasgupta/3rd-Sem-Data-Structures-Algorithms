#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    int flag, temp, k;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }

        printf("\n Array after pass %d \n", i + 1);
        for (k = 0; k < n; k++)
            printf("%d ", arr[k]);
    }

    printf("\n array after bubble sort\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void selectionSort(int arr[], int n)
{
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        printf("\n Array after pass %d \n", i + 1);
        for (k = 0; k < n; k++)
            printf("%d ", arr[k]);
    }
    printf("\nSorted array using Selection Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    int k;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("\n Array after pass %d \n", i);
        for (k = 0; k < n; k++)
            printf("%d ", arr[k]);
    }
    printf("\nSorted array using Insertion Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n, i, choice;
    srand(time(NULL));
    do
    {
        printf("\nSorting Menu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int arr[100];
        int sortedArr[100];

        switch (choice)
        {
        case 1:
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            printf("Enter the elements :\n");
            for (i = 0; i < n; i++)
                scanf("%d", &arr[i]);
            for (int i = 0; i < n; i++)
            {
                sortedArr[i] = arr[i];
            }
            clock_t start_bubble = clock();
            bubbleSort(sortedArr, n);
            clock_t end_bubble = clock();
            printf("\nTime taken: %f seconds\n", ((double)(end_bubble - start_bubble)) / CLOCKS_PER_SEC);
            break;
        case 2:
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            printf("Enter the elements :\n");
            for (i = 0; i < n; i++)
                scanf("%d", &arr[i]);
            for (int i = 0; i < n; i++)
            {
                sortedArr[i] = arr[i];
            }
            clock_t start_selection = clock();
            selectionSort(sortedArr, n);
            clock_t end_selection = clock();
            printf("\nTime taken: %f seconds\n", ((double)(end_selection - start_selection)) / CLOCKS_PER_SEC);
            break;
        case 3:
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            printf("Enter the elements :\n");
            for (i = 0; i < n; i++)
                scanf("%d", &arr[i]);
            for (int i = 0; i < n; i++)
            {
                sortedArr[i] = arr[i];
            }
            clock_t start_insertion = clock();
            insertionSort(sortedArr, n);
            clock_t end_insertion = clock();
            printf("\nTime taken: %f seconds\n", ((double)(end_insertion - start_insertion)) / CLOCKS_PER_SEC);
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Enter a valid choice.\n");
        }
    } while (choice != 4);
    printf("\n");

    return 0;
}