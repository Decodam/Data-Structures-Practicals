#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

int top = -1;
char stack[MAX];

void push(int val)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        top = top + 1;
        stack[top] = val;
    }
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow!");
    }
    else
    {
        int item = stack[top];
        top = top - 1;
        return item;
    }
}

int evaluate(char exp[MAX])
{
    int a, b, result;

    for (int i = 0; exp[i] != ';'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else{
            a = pop();
            b = pop();

            switch (exp[i])
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            
            default:
                break;
            }
        }

        return result;
    }
}

int main()
{
    char postFix[MAX];

    printf("Enter the expression, end it with ';' symbol:    "); fgets(postFix, MAX, stdin);


    int result = evaluate(postFix);

    printf("\n \nResult = %d", result);
    return 0;
}