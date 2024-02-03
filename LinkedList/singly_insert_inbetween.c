#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **start_ref, struct node *temp)
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


void insert_inbetween_after(struct node *temp)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    int target;
    int input;

    printf("\nEnter after which data you want to insert : ");
    scanf("%d", &target);

    while (temp->next != NULL)
    {
        if(temp->data == target){
            printf("\nenter data to be stored : ");
            scanf("%d", &input);

            newnode->next = temp->next;
            temp->next = newnode;
            newnode->data = input;
            break;
        }
        temp = temp->next;
        if(temp->next == NULL)
        {
            printf("Entered Value Not Found In Linked List");
        }
    }
}

void insert_inbetween_before(struct node *temp)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    int target;
    int input;

    printf("\nEnter before which data you want to insert : ");
    scanf("%d", &target);

    while (temp->next != NULL)
    {
        if(temp->next->data == target){
            printf("\nenter data to be stored : ");
            scanf("%d", &input);

            newnode->next = temp->next;
            temp->next = newnode;
            newnode->data = input;
            break;
        }
        temp = temp->next;
        if(temp->next == NULL)
        {
            printf("Entered Value Not Found In Linked List");
        }
    }
}

int main()
{
    int i, target;
    struct node *start = NULL;

    for (i = 0; i < 3; i++)
    {
        insert(&start, start);
    }
    displayData(start);
    insert_inbetween_after(start);
    insert_inbetween_before(start);
    displayData(start);
}