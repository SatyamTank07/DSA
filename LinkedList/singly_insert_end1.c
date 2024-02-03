#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

void insert_end(struct node *temp){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    int input;
    printf("enter data to be stored : ");
    scanf("%d",&input);
    temp->next = newnode;
    newnode->data = input;
    newnode->next = NULL;
    
}

void displayData(struct node *temp){
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main(){
    int i;
    struct node first_node;
    first_node.data= 111;
    first_node.next= NULL;
    struct node *start = &first_node;
    for(i=0;i<3;i++){
        insert_end(start);
    }
     displayData(start->next);
}