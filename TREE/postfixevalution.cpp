#include <iostream>
#include <conio.h>
#include <cstring>
#include <math.h>
using namespace std;
char postfix[30];
int top = -1;
float s[10];
// void push(char ch);
// char pop();
void push(float ch)
{
    top++;
    s[top] = ch;
}

char pop()
{
    float ch;
    ch = s[top];
    top--;
    return ch;
}

int main()
{
    int l,i;
    float a, b;
    char x;
    cout << "Enter postfix expression\n";
    cin >> postfix;
    // p = "5+36-";
    l = strlen(postfix);
    for (i = 0; i < l; i++)
    {
       // cout<<postfix[i]<<"\n";
        switch (postfix[i])
        {
            
        case '^':
            a = pop();
            b = pop();
            push(pow(b, a));
            break;
        case '/':
            a = pop();
            b = pop();
            push(b/a);
            break;
        case '*':
            a = pop();
            b = pop();
            push(b*a);
            break;
        case '+':
            a = pop();
            b = pop();
            push(b+a);
            break;
        case '-':
            a = pop();
            b = pop();
            push(b-a);
            break;
        default:
            x=postfix[i];
            push(atof(&x));
            break;
        }

    }

    cout << "The result of given postfix expression is :" << s[top] << "\n";

    getch();
    return 0;
}