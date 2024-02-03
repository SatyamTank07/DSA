#include<iostream>
#include<string>
#include<cctype>

using namespace std;

char stack[50];
int top=-1;

int prec(char c)
{
    if(c=='+' or c=='-') return 1;
    if(c=='*' or c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}

bool isOp(char x)
{
    return(x=='+'|| x=='-'|| x=='*'|| x=='/'|| x=='^');
}


void push(char x)
{
    stack[++top]=x;
}

void pop()
{
    stack[top--]=0;
}
char peek()
{
    return stack[top];
}

string infpp(const string &infix)
{
    string postfix;

    for(int i=0;i<infix.length();i++)
    {
        if(isalnum(infix[i]))
            postfix += infix[i];

        else if(infix[i]=='(')
            push(infix[i]);

        else if(infix[i]==')')
        {   while(top!=-1 && peek()!='(')
            {
                postfix += peek();
                pop();
            }
            pop();
        }
        
        else if(isOp(infix[i]))
        {
            while(top!=-1 && prec(infix[i])<=prec(peek()))
            {
                postfix += peek();
                pop();
            }
            push(infix[i]);
        }

    }
    while(top!=-1)
    {
        postfix += peek();
        pop();
    }
    return postfix;
}

int main()
{
    string infix;
    cout<<"Enter Your Infix Expression:";
    cin>>infix;
    cout<<"\n\nInfix expression: "<<infix<<endl;
    cout<<"\nConverted To PP: "<<infpp(infix)<<endl<<endl;

}