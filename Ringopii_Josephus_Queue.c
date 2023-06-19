// Problem: Josephus Queue

#include<stdio.h>
#include<stdlib.h>

#define QUEUE_MAX_SIZE 20
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0
int data[QUEUE_MAX_SIZE];
int front;
int rear;
int length;


void initializeQueue()
{
    front = 0 ;
    rear = 0 ;
    length = 0 ;
}

int enqueue_rotation(int item)
{
    if(length == QUEUE_MAX_SIZE) return NULL_VALUE ;
    data[front] = item ;
    front = (front + 1) % QUEUE_MAX_SIZE ;
    length++ ;
    return SUCCESS_VALUE ;
}

int dequeue_rotation()
{
    if(length == 0) return NULL_VALUE ;
    int item = data[rear] ;
    rear = (rear + 1) % QUEUE_MAX_SIZE ;
    length-- ;
    return item ;
}

void josephus(int n){

    int m;
    for(int i = 0; i<= n - 2; i++)
    {
        m = dequeue_rotation();
        enqueue_rotation(m);
        dequeue_rotation();
    }

}


void PrintAll()
{
    int i,k;
    for(i=rear,k=0;k<length;i++,k++)
    {
        printf("%d ",data[i%QUEUE_MAX_SIZE]);
    }
    printf("\n");
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i<=n; i++){
        enqueue_rotation(i);
    }

    josephus(n);

    PrintAll();

}

