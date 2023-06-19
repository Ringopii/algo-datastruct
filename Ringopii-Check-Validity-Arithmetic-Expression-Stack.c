// Check Validity of an Arithmetic Expression using the Stack Data Structure

#include <stdio.h>
#include <string.h>
int top = -1;
void push(char item, char stack[])
{
    stack[++top] = item;
}

void pop()
{
    if (top == -1)
    {
        printf("Invalid Expression!");
        return;
    }
    else
        --top;
}

char checkStack(char stack[])
{
    return stack[top];
}

int main()
{
    char exprsn[100];
    int count = 0;

    printf("Enter an arithmetic expression: ");
    scanf("%s", &exprsn);

    int exprsn_length = strlen(exprsn);

    for (int i = 0; i < exprsn_length; i++)
    {
        if (exprsn[i] == '(' || exprsn[i] == '{' || exprsn[i] == '[')
        {
            count++;
        }
    }

    char stack[count];

    for (int i = 0; i < exprsn_length; i++)
    {
        if (exprsn[i] == '(')
        {
            push(exprsn[i], stack);
        }
        else if (exprsn[i] == '{')
        {
            push(exprsn[i], stack);
        }
        else if (exprsn[i] == '[')
        {
            push(exprsn[i], stack);
        }
        if (exprsn[i] == ')')
        {
            if (checkStack(stack) == '(')
            {
                pop();
            }
            else
            {
                printf("Invalid Expression!");
                return 0;
            }
        }
        else if (exprsn[i] == '}')
        {
            if (checkStack(stack) == '{')
            {
                pop();
            }
            else
            {
                printf("Invalid Expression!");
                return 0;
            }
        }
        else if (exprsn[i] == ']')
        {
            if (checkStack(stack) == '[')
            {
                pop();
            }
            else
            {

                printf("Invalid Expression!");
                return 0;
            }
        }
    }

    if (top == -1)
    {
        printf("Valid Expression");
    }
    else
    {
        printf("Invalid Expression!");
    }

    return 0;
}