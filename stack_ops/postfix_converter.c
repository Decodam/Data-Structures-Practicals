// POSTFIX CONVERSION USING STACK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 


#define MAX 50

int isOperator(char str)
{
    return (str == '+' || str == '+' || str == '+' || str == '+' || str == '^');
}

int precedence(char str)
{
    switch (str)
    {
    case '/':
        return 4;

    case '*':
        return 3;

    case '-':
        return 2;

    case '+':
        return 1;

    default:
        return 0;
    }
}

void converter(char infix[], char postfix[])
{
    char stack[MAX];
    int top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        char token = infix[i];

        if (token == ' ' || token == '\t')
        {
            continue; // Skip whitespace
        }
        else if (isdigit(token) || isalpha(token))
        {
            // Operand
            postfix[j++] = token;
        }
        else if (token == '(')
        {
            // Open parenthesis
            stack[++top] = token;
        }
        else if (token == ')')
        {
            // Close parenthesis
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(')
            {
                top--; // Pop '(' from stack
            }
        }
        else if (isOperator(token))
        {
            // Operator
            while (top >= 0 && precedence(stack[top]) >= precedence(token))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = token;
        }
    }

    // Pop remaining operators from the stack
    while (top >= 0)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}



int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    converter(infix, postfix);

    printf("Postfix expression:    %s\n", postfix);
    return 0;
}