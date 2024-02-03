#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;
char postexp[30];
float stack[10];
int top = -1;

void push(float ch)
{
    top++;
    stack[top] = ch;
}
char pop()
{
    float ch;
    ch = stack[top];
    top--;
    return ch;
}
int main()
{
    float a, b;
    char x;
    cout << "Enter the Post Fix Expression : ";
    cin >> postexp;

    int l = strlen(postexp);
    for (int i = 0; i < l; i++)
    {
        switch (postexp[i])
        {
        case '^':
            a = pop();
            b = pop();
            push(pow(b, a));
            break;

        case '/':
            a = pop();
            b = pop();
            push(b / a);
            break;

        case '*':
            a = pop();
            b = pop();
            push(b * a);
            break;

        case '+':
            a = pop();
            b = pop();
            push(b + a);
            break;

        case '-':
            a = pop();
            b = pop();
            push(b - a);
            break;

        default:
            x = postexp[i];
            push(atof(&x));
            break;
        }
    }
    cout << "The result of given postfix expression is :" << stack[top] << "\n";

    return 0;
}