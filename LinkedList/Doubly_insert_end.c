#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void insert(struct node **start_ref, struct node *temp)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    int input;
    printf("\nEnter Data For Node : ");
    scanf("%d", &input);

    if (temp == NULL)
    {
        newnode->prev = NULL;
        *start_ref = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    newnode->data = input;
    newnode->next = NULL;
}

void displayData(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    struct node *start = NULL;
    int i;
    for (i = 0; i < 3; i++)
    {
        insert(&start, start);
    }
    displayData(start);
}