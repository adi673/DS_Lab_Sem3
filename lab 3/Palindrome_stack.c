#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
char a[MAXSIZE],b[MAXSIZE];
int top=-1;
//elements will be pushed in a, and popped in b
void push(char ele)
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
char pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return 'x';
    }
    else
        return a[top--];
}
int main()
{
    char c[10];
    int i;
    printf("enter a string\n");
    scanf("%s",c);
    for(i=0;c[i]!='\0';i++)
        push(c[i]);
    for(i=0;a[i]!='\0';i++)
        b[i]=pop();
    if(strcmp(a,b)==0)
    {
        printf("it is palindrome");
    }
    else
        printf("Not a palindrome");
    return 0;
}
