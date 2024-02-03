#include<stdio.h>
#include<malloc.h>

struct node{
    struct node* next;
    int data;
};

void enqueue(struct node** start){
    struct node *temp = start;

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    
    int data;
    printf("Enter Data for node : ");
    scanf("%d", &data);

    if(temp == NULL){
        start = new_node;
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    new_node->next = NULL;
    new_node->data = data;
}

void dequeue(struct node**start_ref){
    struct node *temp = *start_ref;
    *start_ref = temp->next;
    free(temp);
}
int peek(struct node**start_ref){
    struct node *temp = *start_ref;
    return temp->data;
}

void displayqueue(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main(){

    struct node* start=NULL;
    for(int i=0;i<5;i++){
        enqueue(&start);
    }
    // displayqueue(start);
    // dequeue(&start);
    // displayqueue(start);
    return 0;
}