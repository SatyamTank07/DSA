#include <stdio.h>

void push(int queue[], int size, int *front, int *rear)
{
    if (*rear < size)
    {
        int data;
        printf("Enter value : ");
        scanf("%d", &data);
        *rear += 1;
        if (*front == -1)
        {
            *front += 1;
        }
        queue[*rear] = data;
    }
    else
    {
        printf("Overflow");
    }
}

void pop(int queue[],int *front, int*rear)
{
    if(*front==-1)
    {
        printf("Underflow");
    }
    else
    {
        queue[*front]=0;
        if(*front == *rear)
        {
            *front = *rear = -1;
            printf("Deleted The Last Item, Now The List is empty ");
        }
        else
        {
            printf("Deleted The Item at index");
            *front += 1;
        }
    }
}

void dispaly(int queue[], int n)
{
    printf("\n");
    int i = 0;
    while (i < n)
    {
        printf("%d  ", queue[i]);
        i++;
    }
}

int main()
{
    int queue[10];
    int n = 3;
    int front = -1, rear = -1;
    for (int i = 0; i < n; i++)
    {
        push(queue, n, &front, &rear);
    }
    dispaly(queue, n);
    pop(queue,&front,&rear);
    dispaly(queue, n);

}