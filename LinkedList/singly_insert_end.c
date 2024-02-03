#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

void insert_end(struct node **start_ref, struct node *temp)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    int input;
    printf("enter data to be stored : ");
    scanf("%d", &input);

    if (temp == NULL)
    {
        *start_ref = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
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
    int i;
    struct node *start = NULL;
    for (i = 0; i < 3; i++)
    {
        insert_end(&start, start);
    }
    displayData(start);
}