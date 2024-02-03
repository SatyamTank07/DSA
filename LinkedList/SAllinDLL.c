#include <stdio.h>
#include <stdlib.h>
struct node     //structure to create the Node
{
    int info;
    struct node *prev, *next;
};

struct node *start = NULL;      //creating the 'start' node such that its scope remains global
struct node *end = NULL;        //creating the 'end' node such that its scope remains global

//before performing operations on the nodes first we will create a list of n nodes given by user.
void createList()
{
    struct node *newnode;
    int i, n, data;
    printf("Enter the No. of nodes you want to create\n");
    scanf("%d", &n);
    if (n >= 1)
    {
        start = (struct node *)malloc(sizeof(struct node));
        if (start != NULL)
        {
            printf("Enter the data in node 1\n");
            scanf("%d", &data);
            start->info = data;
            start->prev = NULL;
            start->next = NULL;

            end = start;

            for (i = 2; i <= n; i++)
            {
                newnode = (struct node *)malloc(sizeof(struct node));
                if (newnode != NULL)
                {
                    printf("Enter the data in node %d\n", i);
                    scanf("%d", &data);

                    newnode->info = data;
                    newnode->prev = end;
                    newnode->next = NULL;

                    end->next = newnode;
                    end = newnode;
                }
                else
                {
                    printf("unable to allocate memory\n");
                    break;
                }
            }
            printf("Doubly LinkedList created successfully\n");
        }
        else
        {
            printf("Unable to allocate memory\n");
        }
    }
}
//  it will used to go through entire elements of the list one after another.
void traverse()
{
    struct node *temp;
    int n = 1;
    if (start == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        temp = start;
        printf("The data in  the list is:-\n");

        while (temp != NULL)
        {
            printf("\nNode %d: %d\n", n, temp->info);
            n++;
            temp = temp->next;
        }
    }
}
//To insert a new element at the begining of the list.
void insertAtFirst()
{
    struct node *newnode;
    int data;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        printf("Memory not allocated\n");
    else
    {
        printf("Enter the data in the node\n");
        scanf("%d", &data);
        newnode->info = data;
        newnode->prev = NULL;
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
}
//To insert a new element at the ending of the list.
void insertAtEnd()
{
    struct node *newnode;
    int data;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        printf("Memory not allocated\n");
    else
    {
        printf("Enter the data in newnode\n");
        scanf("%d", &data);
        newnode->info = data;
        newnode->next = NULL;
        end->next = newnode;
        newnode->prev = end;
        end = newnode;
    }
}
//To delete the node at the begining of the list. 
/*void deleteAtfirst()
{
    struct node *temp;
    temp = start;
    if (start == NULL)
        printf("the list is empty\n");
    else
    {
        start = start->next;
        if (start != NULL)
        {
            start->prev = NULL;
            free(temp);
        }
    }
}*/


void deleteAtfirst()
{
    struct node *temp;
    temp = start;
    if (start == NULL)
        printf("the list is empty\n");
    else if(start==end)
    {
        start=NULL;
        end=NULL;
        free(temp);
    }
    else
    {
        start=start->next;
        start->prev=NULL;

    }

}


//To delete the node at the ending of the list.


/*
void deleteAtEnd()
{
    struct node *temp;
    temp = end;
    if (end == NULL)
        printf("The list is empty\n");
    else
    {
        end = end->prev;
        if (end != NULL || end == start)
        {
            end->next = NULL;
            free(temp);
        }
        else
        {
            start = NULL;
            free(temp);
        }
    }
}*/


void deleteAtEnd()
{
    struct node *temp;
    temp = end;
    if (start == NULL)
        printf("the list is empty\n");
    else if(start==end)
    {
        start=NULL;
        end=NULL;
        free(temp);
    }
    else
    {
        end=end->prev;
        end->next=NULL;

    }
}



//To insert the node before the given node in linked list.
void insertBeforeNode()
{
    struct node *newnode, *temp;
    int data, target;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data in new node\n");
    scanf("%d", &data);
    newnode->info = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("Enter the data of node before which you want to insert newnode\n");
    scanf("%d", &target);
    temp = start;
    while (temp != NULL && temp->info != target)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Sorry no such node found\n");
    }
    else if (temp == start)
    {
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
    else
    {
        temp->prev->next = newnode;
        newnode->prev = temp->prev;
        newnode->next = temp;
        temp->prev = newnode;
    }
}
//To insert the node after the given node in linked list.
void insertAfterNode()
{
    struct node *newnode, *temp;
    int data, target;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data in new node\n");
    scanf("%d", &data);
    newnode->info = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("Enter the data of node before which you want to insert newnode\n");
    scanf("%d", &target);
    temp = start;
    while (temp != NULL && temp->info != target)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Sorry no such node found\n");
    }
    else if (temp == end)
    {
        newnode->prev = end;
        end->next = newnode;
        end = newnode;
    }
    else
    {
        temp->next->prev = newnode;
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
    }
}
//To delete the node before the given node in linked list.
void deleteBeforeNode()
{
    struct node *temp;
    int target;
    printf("Enter the target before which you want to delete a node...\n");
    scanf("%d", &target);
    temp = start;
    while ((temp != NULL && temp->info != target))
    {
        temp = temp->next;
    }
    if (temp == NULL || temp == start)
    {
        printf("Sorry no node found\n");
    }
    else if (temp->prev == start)
    {

        free(temp->prev);
        temp->prev = NULL;
        start = temp;
    }
    else
    {

        temp = temp->prev;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}
//To delete the node after the given node in linked list.
void deleteAfterNode()
{
    struct node *temp, *a;
    int target;
    printf("Enter the target before which you want to delete a node...\n");
    scanf("%d", &target);
    temp = start;
    while (temp != NULL && temp->info != target)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp == end)
    {
        printf("Sorry no node found\n");
    }
    else if (temp->next == end)
    {
        free(temp->next);
        temp->next = NULL;
        end = temp;
    }
    else
    {
        temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

int main()
{
    //creates the list by takking no. of nodes as input from user.
    createList();
    int choice;
    while ((1))
    {
        printf("\n\t1 To see list\n");
        printf("\n\t2 To insert a node at begining of the list\n");
        printf("\n\t3 To insert a node at Ending of the list\n");
        printf("\n\t4 To delete a node from begining of the list\n");
        printf("\n\t5 To delete a node from ending of the list\n");
        printf("\n\t6 To insert before a given node\n");
        printf("\n\t7 To insert after a given node\n");
        printf("\n\t8 To delete before a given node\n");
        printf("\n\t9 To delete after a given node\n");
        printf("\n\t10 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);

    //using the switch case to call the function according to user input.
        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFirst();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            deleteAtfirst();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            insertBeforeNode();
            break;
        case 7:
            insertAfterNode();
            break;
        case 8:
            deleteBeforeNode();
            break;
        case 9:
            deleteAfterNode();
            break;
        case 10:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }

    return 0;
}