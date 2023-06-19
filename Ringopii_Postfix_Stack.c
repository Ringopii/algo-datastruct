// Problem: Postfix Stack

#include<stdio.h>
#include<string.h>
#include<stdint.h>

#define STACK_MAX_SIZE 100
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0
int data[STACK_MAX_SIZE];
int top;
int flag = 0;


void initializeStack()
{
    top = 0 ;
}

int push(int item)
{
    if(top == STACK_MAX_SIZE){
        return NULL_VALUE ;
    }
    else if(flag == 0){
        data[top] = item;
        top++ ;
        flag = 1;
    }
    else
    {
        int itemA;
        itemA = pop();
        item = 10*itemA + item;
        data[top] = item;
        top++;
    }
    return SUCCESS_VALUE ;
}

int pop()
{
    if(top == 0) return FALSE_VALUE ;
    top--;
    return data[top];
}




void postfixfunc(char input[])
{

    for(int i = 0; input[i] != '\0'; i++)
    {
         if(isdigit(input[i]))
		{
			push(input[i]-'0');
		}

		else if(input[i]==' ')
        {
            flag=0;
        }

        else if((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/'))
        {
            int a = pop();
            int b = pop();
            flag=0;

            int output=0;
            switch(input[i])
            {
            case '+':
                output = b + a;
                push(output);
                break;

            case '-':
                output = b - a;
                push(output);
                break;

            case '*':
                output = b * a;
                push(output);
                break;

            case '/':
                output = b / a;
                push(output);
                break;
            }
        }
    }
    printf("\n%d\n",pop());
}


int main()
{
    char input[100];
    fgets(input,100,stdin);

    postfixfunc(input);

return 0;
}
