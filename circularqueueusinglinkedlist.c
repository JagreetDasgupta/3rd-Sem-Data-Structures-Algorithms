#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (!q)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct Queue *q)
{
    return (q->front == NULL);
}

void enqueue(struct Queue *q, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
        q->rear->next = q->front; // Circular link
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front; // Circular link
    }
    printf("%d has been inserted into the queue.\n", data);
}

void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = q->front;
    int data = temp->data;

    if (q->front == q->rear)
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
        q->rear->next = q->front; // Update the circular link
    }

    free(temp);
    printf("%d has been deleted from the queue.\n", data);
}

void displayQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *current = q->front;
    printf("Queue elements: ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != q->front);
    printf("\n");
}

int main()
{
    struct Queue *q = createQueue();
    int choice, item;

    while (1)
    {
        printf("\nCircular Queue Menu:\n");
        printf("1. Insert (enqueue) element\n");
        printf("2. Delete (dequeue) element\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &item);
            enqueue(q, item);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            displayQueue(q);
            break;
        case 4:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}