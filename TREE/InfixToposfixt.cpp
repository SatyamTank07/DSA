#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;
char stack[50], postfix[50], infix[50];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char ch;
    ch = stack[top];
    top--;
    return ch;
}

int main()
{
    int i, j = 0, len;
    cout << "Enter Infix Expression\n";
    cin >> infix;
    // cout<<infix;
    len = strlen(infix);
    for (i = 0; i < len; i++)
    {
        switch (infix[i])
        {

        case '(':
            push('(');
            break;
        case '^':
            while (stack[top] == '^')
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
            break;

        case '/':
        case '*':
            while (stack[top] == '^' || stack[top] == '/' || stack[top] == '*')
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
            break;

        case '+':
        case '-':
            while (stack[top] == '^' || stack[top] == '/' || stack[top] == '*' || stack[top] == '+' || stack[top] == '-')
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
            break;
        case ')':
            while (stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            top--;
            break;
        default:
            postfix[j] = infix[i];
            j++;
            break;
        }
    }

    while (top!=-1)
    {
        postfix[j]=pop();
        j++;
    }

    postfix[j]='\0';

    cout<<"The postfix of above Expresion is: "<<p<<"\n";
    
    getch();
    return 0;
}