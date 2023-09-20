#include<stdio.h>
#define MAXSIZE 20
int a[MAXSIZE],b[MAXSIZE];
int top=-1;
void push(int ele)
{
    if(top==MAXSIZE-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        a[++top]=ele;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return -999;
    }
    else
        return a[top--];
}
void bcd_convert(int ele,int base)
{
    int num=0,i,x;
    while(ele!=0){
        push(ele%base);
        ele=ele/base;
    }
    while(top!=-1){
    x=pop();
    if(x<=9)
        printf("%d",x);
    else
        printf("%c",x+55);}
}
int main()
{
    int num,base;
    printf("enter number\n");
    scanf("%d",&num);
    printf("enter base for conversion:\n");
    scanf("%d",&base);
    bcd_convert(num,base);
    return 0;
}
