#include<stdio.h>
#define maxsize 5
int a[maxsize],front=0,rear=0,i;
void insert(int ele)
{
    if((rear+1)%maxsize==front)
        printf("queue is full");
    else
    {
        rear=(rear+1)%maxsize;
        a[rear]=ele;
    }
}
int del()
{
    if(front==rear){
        printf("queue is empty");
        return -25;}
    else
    {
        front=(front+1)%maxsize;
        return a[front];
    }
}
void disp()
{
    if (front==rear)
        printf("queue is empty");
    else
    {
        i=front;
        do{
            i=(i+1)%maxsize;
            printf("%d\t",a[i]);
        }while(i!=rear);
    }
}
int main()
{
    insert(5);
    insert(6);
    insert(7);
    del();
    disp();
    return 0;
}
