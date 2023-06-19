// Problem: Singly Linked List (insert and delete items)

#include<stdio.h>
#include<stdlib.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999


struct listNode
{
    int item ; //will be used to store value
    struct listNode *next ; //will keep address of next node
} ;
struct listNode * list ;
int length;

void initializeList()
{
    list = 0 ; //set to NULL
    length=0;
}

int insertItemBegin(int item)
{
    struct listNode * newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->next = list ;
    list = newNode ;
    length++;
    return SUCCESS_VALUE ;
}

struct listNode* searchItem(int item)
{
    struct listNode *temp ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) return temp ;
        temp = temp->next ; //move to next node
    }
    return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

int GetItem(int position)
{
    if(position<0 || position>=length) return NULL_VALUE;
    struct listNode *temp;
    int count=0;
    temp=list;
    while(count<position)
    {
        temp=temp->next;
        count++;
    }
    return temp->item;
}

void PrintALL()
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


int deleteFirstOccurrence(int item)
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    if (temp == list) //delete first node
    {
        list = list->next ;
        free(temp) ;
    }
    else
    {
        prev->next = temp->next ;
        free(temp);
    }
    length--;
    return SUCCESS_VALUE ;
}




//Assignment
int insertItemLast(int item)// Insert item at the last position of the list
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        prev = temp;
        temp = temp->next ; //move to next node
        if (temp == NULL)
        {
            struct listNode * newNode ;
            newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
            newNode->item = item ;
            newNode->next = NULL ;
            prev->next = newNode ;
            length++;
            return SUCCESS_VALUE ;
        }
    }
    return 0 ;
}


int insertItemAT(int position, int item)// Insert item at the given position of the list
{
    if(position<=0 || position>=length) return NULL_VALUE;
    struct listNode *temp, *prev;
    int count=0;
    temp=list;
    while(count!=position)
    {
        prev = temp;
        temp=temp->next;
        count++;
        if(count == position)
        {
            struct listNode * newNode ;
            newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
            newNode->item = item ;
            newNode->next = prev->next ;
            prev->next = newNode ;
            length++;
            return SUCCESS_VALUE ;
        }
    }
    return 0;

}


int NumOfItems(int item)// return the number of the occurrence of the given item
{
    struct listNode *temp;
    int count;
    temp=list;
    while(temp != 0)
    {
        if(temp->item == item){
          count++;
        }
        temp=temp->next;
    }

    return count;
}


int deleteALLOccurrence(int item)// Delete all the occurrence of the given item in the list with preserving order
{
    struct listNode *temp, *prev, *p ;
    temp=list;
    while(temp != 0 && temp->item == item)
    {
                list = list->next ;
                temp = list;
                length--;

    }

    while(temp != 0){

        while(temp != 0 && temp->item != item)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp == 0) return NULL_VALUE;
        prev->next = temp->next;
        temp = prev->next;
        length--;
    }

    return SUCCESS_VALUE;
}


int deleteLastOccurrence(int item)// Delete the last occurrence of the given item in the list
{
    struct listNode *temp, *prev, *s ;
    temp=list;
    while(temp!= 0){

        if(temp->next!= 0 && temp->next->item == item){
            s = temp;
        }

        temp = temp->next;
    }
    if(s!= 0)
        {
            temp = s->next;
            s->next = s->next->next;
            free(temp) ;
            length--;
        }

    return SUCCESS_VALUE;
}


int deleteFirstItem() // delete the first item of the list
{
    struct listNode *temp ;
    temp = list ; //start at the beginning
    list = list->next ;
    free(temp) ;
    length--;
    return SUCCESS_VALUE ;
}


int deletelastItem()// delete the last item of the list
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        prev = temp;
        temp = temp->next ; //move to next node
        if (temp->next == NULL)
        {   prev->next = NULL ;
            free(temp) ;
            length--;
            return SUCCESS_VALUE ;

        }
    }

    return 0;

}

int main()
{
    char inp1, chk;
    int inp2,inp3;
    int s;
    initializeList();
    while(1){
        scanf("%c",&inp1);


        switch(inp1)
        {
        case 'I':
            scanf("%d",&inp2);
            s=insertItemBegin(inp2);
            break;
        case 'G':
            scanf("%d",&inp2);
            s=GetItem(inp2);
            printf("%d\n",s);
            break;
        case 'S':
            scanf("%d",&inp2);
            printf("Address: %d\n",searchItem(inp2));
            break;
        case 'R'://delete the item of first occurrence
            scanf("%d",&inp2);
            s=deleteFirstOccurrence(inp2);
            break;
        case 'P':
            PrintALL();
            break;
        case 'L':
            printf("Length: %d\n",length);
            break;
        case 'i':// Insert item at the last position of the list
            scanf("%d",&inp2);
            s=insertItemLast(inp2);
            break;
        case 'A':// Insert item at the given position of the list
            scanf("%d %d",&inp2, &inp3);
            s=insertItemAT(inp2, inp3);
            break;
        case 'D':// Delete the first item of the list
            deleteFirstItem();
            break;
        case 'd':// Delete the last item of the list
            deletelastItem();
            break;
        case 'O':// Return the number of the occurrence of the given item
            scanf("%d",&inp2);
            s=NumOfItems(inp2);
            printf("Number of Occurrences: %d",s);
            break;
        case 'a':// Delete all the occurrence of the given item in the list with preserving order
            scanf("%d",&inp2);
            s=deleteALLOccurrence(inp2);
            break;
        case 'l':// Delete the last occurrence of the given item in the list with preserving order
            scanf("%d",&inp2);
            s=deleteLastOccurrence(inp2);
            break;
        }
        if(s==NULL_VALUE) break;
    }

}

