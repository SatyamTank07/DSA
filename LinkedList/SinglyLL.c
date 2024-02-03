#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *createnode(int data){
    struct node *newnode= (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct node *insertbeg(struct node *start, int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=start;
    start = newnode;
    return start;
}

void display(struct node *ptr){
    while (ptr != NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    
}

int main(){

struct node *start = NULL;
int data=5,i,n=3;

// printf("How many node you want : ");
// scanf("%d",&n);

for(i=0;i<n; i++){
    // printf("Enter the data : ");
    // scanf("%d",&data);
    struct node *newnode = createnode(data+i);
    if(start == NULL){
        start=newnode;
    }else{
        struct node *p;
        p=start;
        while(p->next != NULL){
            p=p->next;
        }
        p->next=newnode;
    }
}
	// printf("Enter data u want to enter insert at beginning:");
	// scanf("%d",&data);
    int beg=4;
	start=insertbeg(start,beg);
    display(start);
// struct node *newnode=createnode(data);
return 0;
}