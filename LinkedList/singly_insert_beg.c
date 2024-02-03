#include<stdio.h>
#include<malloc.h>


struct node{
    int data;
    struct node *next;
};

void insert_beg(struct node **start){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    int input;
    printf("\nEnter Data For Node : ");
    scanf("%d",&input);

    newnode->data = input;
    newnode->next = *start;
    *start = newnode;
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
    struct node *start=NULL;
    for(i=0;i<3;i++){
        insert_beg(&start);
    }
    displayData(start);
}
