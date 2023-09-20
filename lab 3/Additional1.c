#include<stdio.h>
#define stack_size 9
#define no_stack 3
int top[5],b[5],stack[10];

int pop(int i){
    if(top[i]==b[i]){
        printf("stack is empty\n");
        return -1;
    }
    else
        return stack[top[i]--];
}
void push(int i, int item)
{
    if(top[i]==b[i+1])
        printf("stack is full\n");
    else
        stack[++top[i]]=item;
}
void disp(int i){
    if(top[i]==b[i])
        printf("stack is empty\n");
    else
        for(int j=b[i]+1;j<=top[i];j++)
    {
        printf("%d\n",stack[j]);
    }
}
int main(){
    int i;
    //initialize;
    for(i=0;i<no_stack;i++)
    {
        top[i]=b[i]=((stack_size/no_stack)*i)-1;
    }
    b[i]=stack_size-1;
    push(0,1);
    push(1,2);
    push(2,3);
    printf("%d\n",pop(2));
    disp(0);
    disp(1);
    return 0;
}
