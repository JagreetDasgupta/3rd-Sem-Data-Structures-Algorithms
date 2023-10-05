#include <stdio.h>
int arr[100];
int top = -1, i;
// defining functions
void push(int data)
{
    if (top == 100)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        top++;
        arr[top] = data;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("UNDERFLOW");
    }
    else
    {
        printf("THE DATA DELTED FROM STACK IS %d\n", arr[top]);
        top--;
    }
}
void peep()
{
    if (top == -1)
    {
        printf("No data present in stack\n");
    }
    else
    {
        printf("THE TOP MOST ELEMENT IS%d\n", arr[top]);
    }
}
void display()
{
    if (top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        for (i = 0; i <= top; i++)
        {
            printf("%d\n", arr[i]);
        }
    }
}
int main()
{
    int data, choice;
    while (1)
    {
        printf("----MENU DRIVEN STACK----\n");
        printf("ENTER 1 TO INSERT DATA INTO STACK\n");
        printf("ENTER 2 TO DELETE DATA FROM STACK\n");
        printf("ENTER 3 TO VIEW THE TOP MOST ELEMENT IN STACK\n");
        printf("ENTER 4 TO DISPLAY ELEMENTS IN THE STACK\n");
        printf("ENTER 5 TO EXIT FROM THE PROGRAM\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER THE DATA:\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("INVALID CHOICE!\n");
            break;
        }
    }
}
