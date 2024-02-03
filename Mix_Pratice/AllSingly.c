#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *next;
    int data;
};

void insertBeg(struct node **start_ref)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    int data;
    printf("Enter Data for node : ");
    scanf("%d", &data);

    new_node->data = data;
    new_node->next = *start_ref;
    *start_ref = new_node;
}

void insertEnd(struct node **start_ref, struct node *temp)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    int data;
    printf("Enter Data for node : ");
    scanf("%d", &data);

    if (temp == NULL)
    {
        *start_ref = new_node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    new_node->next = NULL;
    new_node->data = data;
}

void insertBeforeNode(struct node *temp)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    int target;
    printf("Enter Target Data for Before node : ");
    scanf("%d", &target);

    while (temp->next != NULL)
    {
        if ((temp->next->data == target))
        {
            int data;
            printf("Enter Data for node : ");
            scanf("%d", &data);

            new_node->next = temp->next;
            temp->next = new_node;
            new_node->data = data;
            break;
        }
        temp = temp->next;
        if(temp->next ==NULL){
            printf("Moye Moye");
        }
    }
}

void insertAfterNode(struct node *temp)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    int target;
    printf("Enter Target Data for After node : ");
    scanf("%d", &target);

    while (temp->next != NULL)
    {
        if ((temp->data == target))
        {
            int data;
            printf("Enter Data for node : ");
            scanf("%d", &data);

            new_node->next = temp->next;
            temp->next = new_node;
            new_node->data = data;
            break;
        }
        temp = temp->next;
        if(temp->next ==NULL){
            printf("Moye Moye");
        }
    }
}

void deletebeg(struct node **start_ref,struct node *temp)
{
	*start_ref=temp->next;
	free(temp);
}

void deleteend(struct node *temp)
{
	while(temp->next->next!=NULL)
	{	
		temp=temp->next;
	}
	free(temp->next->next);
	temp->next=NULL;
}

void deletenode(struct node *temp)
{
    struct node* delvar;
    int target;
    printf("Enter Target Data for Delete : ");
    scanf("%d", &target);
   
	while(temp->next->data != target)
	{
		temp = temp->next;
	}
	delvar = temp->next;
    temp->next = temp->next->next;
    free(delvar);
}

void deletebefore(struct node *temp)
{
    struct node* delvar;

    int target;
    printf("Enter Target Data to Delete before : ");
    scanf("%d", &target);

	while(temp->next->next->data != target)
	{	
        temp = temp->next;
	}

    delvar = temp->next;
    temp->next = temp->next->next;
	free(delvar);
	
}

void deleteafter(struct node *temp)
{
    struct node* delvar;

    int target;
    printf("Enter Target Data to Delete After : ");
    scanf("%d", &target);

	while(temp->data != target)
	{
		temp = temp->next;
	}
    delvar = temp->next;
    temp->next = temp->next->next;
	free(delvar);	
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

    for (i = 0; i < 5; i++)
    {
        // insertBeg(&start);
        insertEnd(&start, start);
    }
    // insertBeforeNode(start);
    // insertAfterNode(start);
    // deletebeg(&start,start);
    // deleteend(start);
    // deletenode(start);
    // deletebefore(start);
    // deleteafter(start);
    displayData(start);
}