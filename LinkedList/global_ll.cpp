#include <iostream>

struct node
{
    int data;
    struct node*next;
};

struct node *start = NULL;


void insert()
{
    int input;
        std::cout<<"Enter A Number";
        std::cin>>input;
        struct node *newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data =input;
        
            newnode->next=start;
            start=newnode;

}
void display()
{
    struct node*temp=start;
    while(temp!=NULL)
    {
        std::cout<<temp->data<<"->";
        temp= temp->next;
    }
    std::cout<<"END";
}

int main()
{
    int i =0;
    while(i<3)
    {   
        insert();
        i++; 
    }
    display();
}