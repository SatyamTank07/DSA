#include<iostream>

void push(int stack[], int n, int *head)
{
    int input;
   
    if(*head<n)
    {
        std::cout<<"enter value to store:";
        std::cin>>input;
        *head += 1;
        stack[*head]=input;
    }
    else
    {
        std::cout<<"Overflow"<<std::endl;
    }
}

void pop(int stack[],int *head)
{
    if(*head==-1)
    {
        std::cout<<"Underflow";
        exit(0);
    }
    std::cout<<"Deleting :"<<stack[*head]<<std::endl;
    stack[*head]=0;
    *head -= 1;
}

void search(int stack[], int head)
{
    std::cout<<"Enter The VAlue You Want to Search:";
    int input;
    std::cin>>input;
    while(head!=-1)
    {
        if(stack[head]==input)
        {
            std::cout<<"Value Found At Index:"<<head+1<<std::endl;
            break;
        }
        head--;
        if(head==-1)
        {
            std::cout<<"value not found"<<std::endl;
            break;
        }
    }
}
int main()
{
    int stack[10];
    int head=-1;
    for(int i=0; i<4; i++)
    {
        push(stack, 2, &head);
    }
    search(stack, head);
    std::cout<<"Head is currently at index: "<<head+1<<std::endl;
    pop(stack,&head);
}