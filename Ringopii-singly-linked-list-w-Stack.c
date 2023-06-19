// Problem: Singly Linked List with Stack 

#include<stdio.h>

#define STACK_MAX_SIZE 100
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0
//int data[STACK_MAX_SIZE];


struct listNode
{
    int item ; //will be used to store value
    struct listNode *next ; //will keep address of next node
} ;
struct listNode * list ;
struct listNode * top ;

void initializeList()
{
    list = 0 ; //set to NULL
}

void initializeStack()
{
    top = 0 ;
}


int push(int item)
{
    struct listNode * newNode, *prev, *temp ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;

    if(top == 0)
    {
        top = newNode;
        newNode->next = 0 ;
        list = newNode ;
    }
    else
    {
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            prev = temp;
            temp = temp->next ; //move to next node
            if (temp == NULL)
            {
                newNode->next = NULL ;
                prev->next = newNode ;
                top = newNode;
            }
        }
    }
    return SUCCESS_VALUE ;
}

int pop()
{
    if(top == 0) return NULL_VALUE ;

    else
    {
        struct listNode *temp, *a, *prev ;
        a = top->item;
        temp = list;
        printf("%d\n",a) ;
        while(temp!=0)
        {
            prev = temp;
            temp = temp->next ; //move to next node
            if (temp->next == NULL)
            {
                prev->next = NULL ;
                free(temp) ;
                top = prev ;
                return SUCCESS_VALUE ;
            }
        }

    }

}


int IsEmpty()
{
    if(top == 0) return TRUE_VALUE ;
    else return FALSE_VALUE ;
}


void PrintAll()
{
    struct listNode *temp;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        printf("%d ",temp->item);
        temp = temp->next ; //move to next node
    }
    printf("\n");
}

int main()
{
    int a,result;
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        switch(ch)
        {
        case 'P':
            scanf("%d",&a);
            result=push(a);
            break;
        case 'p':
            pop();
            break;
        case 's':
            PrintAll();
            break;
        default:
            break;
        }
        if(result==NULL_VALUE) break;
    }

}
