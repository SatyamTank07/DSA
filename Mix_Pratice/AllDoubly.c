#include <stdio.h>
#include <malloc.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

void insertEnd(struct node **start_ref, struct node *temp)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	int data;
	printf("Enter Data For Node : ");
	scanf("%d", &data);

	if (temp == NULL)
	{
		new_node->prev = NULL;
		*start_ref = new_node;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
	}
	new_node->data = data;
	new_node->next = NULL;
}

void insertBeg(struct node **start_ref, struct node *temp)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	int data;
	printf("Enter Data For Node : ");
	scanf("%d", &data);

	if (temp == NULL)
	{
		*start_ref = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = temp;
		temp->prev = new_node;
		*start_ref = new_node;
	}
	new_node->prev = NULL;
	new_node->data = data;
}

void insertBeforeNode(struct node *temp)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	int target;
	printf("Enter target to insert before Node : ");
	scanf("%d", &target);

	int data;
	printf("Enter Data For Node : ");
	scanf("%d", &data);

	while (temp->data != target)
	{
		temp = temp->next;
	}
	temp->prev->next = new_node;
	new_node->prev = temp->prev;
	new_node->next = temp;
	temp->prev = new_node;
	new_node->data = data;
}

void insertAfterNode(struct node *temp)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	int target;
	printf("Enter target to insert After Node : ");
	scanf("%d", &target);

	int data;
	printf("Enter Data For Node : ");
	scanf("%d", &data);

	while (temp->data != target)
	{
		temp = temp->next;
	}
	new_node->next = temp->next;
	temp->next->prev = new_node;
	temp->next = new_node;
	new_node->prev = temp;
	new_node->data = data;
}
void deleteNode(struct node *temp)
{
	struct node *deleteNode;

	int target;
	printf("Enter target to Delete : ");
	scanf("%d", &target);

	while (temp->next->data != target)
	{
		temp = temp->next;
	}
	deleteNode = temp->next;
	temp->next = temp->next->next;
	temp->next->prev = temp;
	free(deleteNode);
}

void deleteBeforeNode(struct node *temp)
{
	struct node *deleteNode;

	int target;
	printf("Enter target to Delete : ");
	scanf("%d", &target);

	while (temp->data != target)
	{
		temp = temp->next;
	}
	deleteNode = temp->prev;
	temp->prev = temp->prev->prev;
	temp->prev->next = temp;
	free(deleteNode);
}

void deleteAfterNode(struct node *temp)
{
	struct node *deleteNode;

	int target;
	printf("Enter target to Delete : ");
	scanf("%d", &target);

	while (temp->data != target)
	{
		temp = temp->next;
	}
	deleteNode = temp->next;
	temp->next = temp->next->next;
	temp->next->prev = temp;
	free(deleteNode);
}

void deleteAtBeg(struct node **start_ref, struct node *temp)
{
	struct node *deleteNode = temp;
	*start_ref = temp->next;
	temp->prev = NULL;
	free(deleteNode);
}

void deleteAtEnd(struct node *temp)
{

	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	struct node *deleteNode = temp->next;
	temp->next = NULL;
	free(deleteNode);
}
void display(struct node *temp)
{
	while (temp != NULL)
	{
		printf("%d-> ",temp->data);
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
		// insertEnd(&start, start);
		insertBeg(&start, start);
	}
	// insertBeforeNode(start);
	// insertAfterNode(start);
	// deleteNode(start);
	// deleteBeforeNode(start);
	// deleteAfterNode(start);
	// deleteAtBeg(&start,start);
	// deleteAtEnd(start);
	display(start);
}

// printf("\n(%p) %d (%p) -> ",temp->prev , temp->data,temp->next);
// (00000000) 1 (007E2F90) ->
// (007E2F78) 2 (007E29B0) ->
// (007E2F90) 3 (007E29C8) ->
// (007E29B0) 4 (007E29E0) ->
// (007E29C8) 5 (00000000) -> NULL