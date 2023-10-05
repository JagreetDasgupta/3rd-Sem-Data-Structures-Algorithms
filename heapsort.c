#include <stdio.h>

void printArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void inputArray(int *arr, int size)
{
	printf("Enter the array: ");
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void max_heapify(int *arr, int size, int i)
{
	int max = i;
	int left = 2 * i + 1, right = 2 * i + 2;
	if (left < size && arr[max] < arr[left])
		max = left;
	if (right < size && arr[max] < arr[right])
		max = right;
	if (max != i)
	{

		swap(&arr[max], &arr[i]);
		max_heapify(arr, size, max);
	}
}

void min_heapify(int arr[], int size, int i)
{
	int min = i;
	int left = 2 * i + 1, right = 2 * i + 2;
	if (left < size && arr[min] > arr[left])
		min = left;
	if (right < size && arr[min] > arr[right])
		min = right;
	if (min != i)
	{
		swap(&arr[min], &arr[i]);
		min_heapify(arr, size, min);
	}
}

void heap_sort(int arr[], int size)
{
	int pass = 1;
	// convert the array into a max_heap
	for (int i = size / 2 - 1; i > -1; i--)
		max_heapify(arr, size, i);
	printf("The heapified array is: \n");
	printArray(arr, size);
	for (int i = size - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		max_heapify(arr, i, 0);
		printf("pass %d: \n", pass++);
		printArray(arr, size);
	}
}

int main()
{
	int size, i;
	printf("Enter Size of the array \n");
	scanf("%d", &size);
	int arr[size];
	printf("Enter Elements \n");
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	printf("The unsroted array is: \n");
	printArray(arr, size);
	heap_sort(arr, size);
	printf("The sorted array is :\n");
	printArray(arr, size);

	return 0;
}