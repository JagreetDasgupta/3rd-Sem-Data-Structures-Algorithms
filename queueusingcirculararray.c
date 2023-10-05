#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Queue
{
	int front, rear;
	int capacity;
	int size;
	int *array;
};
// create an empty queue
struct Queue *create_Queue(int capacity)
{
	struct Queue *Q = malloc(sizeof(struct Queue));
	if (!Q)
		return NULL;
	Q->capacity = capacity;
	Q->front = Q->rear = -1;
	Q->size = 0;
	Q->array = malloc(Q->capacity * sizeof(int));
	if (!Q->array)
		return NULL;
	return Q;
}

int isempty(struct Queue *Q)
{
	return (Q->size == 0);
}
// Return Front Element of the Queue
void frontElement(struct Queue *Q)
{
	if (isempty(Q))
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Front Element:%d\n", Q->array[Q->front]);
}
// Return Rear Element of the Queue
void rearElement(struct Queue *Q)
{
	if (isempty(Q))
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Rear Element:%d\n", Q->array[Q->rear]);
}

// check if queue is full or not
int isfull(struct Queue *Q)
{
	return (Q->size == Q->capacity);
}
// enqueue
void enQueue(struct Queue *Q)
{
	int data;
	if (isfull(Q))
		printf("Queue Overflow\n");
	else
	{
		printf("enter the data you want to enter:");
		scanf("%d", &data);
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = data;
		if (Q->front == -1)
			Q->front = Q->rear;
		Q->size += 1;
	}
}

// dequeue
void deQueue(struct Queue *Q)
{
	int data = INT_MIN;
	if (isempty(Q))
	{
		printf("Queue is empty\n");
		return;
	}
	data = Q->array[Q->front];
	if (Q->front == Q->rear)
	{
		Q->front = Q->rear = -1;
		Q->size = 0;
	}
	else
	{
		Q->front = (Q->front + 1) % Q->capacity;

		Q->size -= 1;
	}
	printf("dequeue: %d\n", data);
}

void displayQueue(struct Queue *Q)
{
	if (isempty(Q))
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements: ");
	int i = Q->front;
	do
	{
		printf("%d ", Q->array[i]);
		i = (i + 1) % Q->capacity;
	} while (i != (Q->rear + 1) % Q->capacity);
	printf("\n");
}

void deleteQueue(struct Queue *Q)
{
	if (Q)
	{
		if (Q->array)
			free(Q->array);
		free(Q);
	}
}

int main()
{
	struct Queue *Q;
	int n, ch;
	printf("enter the capacity of the queue:");
	scanf("%d", &n);
	Q = create_Queue(n);
	while (1)
	{
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Front Element\n");
		printf("4. Rear element\n");
		printf("5.Display\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			enQueue(Q);
			break;
		case 2:
			deQueue(Q);
			break;
		case 3:
			frontElement(Q);
			break;
		case 4:
			rearElement(Q);
			break;
		case 5:
			displayQueue(Q);
			break;
		case 6:
			deleteQueue(Q);
			printf("Exiting...\n");
			exit(1);
		default:
			printf("Invalid Choice:\n");
			break;
		}
	}

	return 0;
}
