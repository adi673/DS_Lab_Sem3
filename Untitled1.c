#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Stack{
 char arr[MAX];
 int top;
};



void initialize(struct Stack *stack){
    stack->top=-1;
}
int isFULL(struct Stack *stack){
  if(stack->top==MAX-1){
    return 1;
  }else{
    return 0;
  }
}
int isEmpty(struct Stack *stack){
  if(stack->top==-1){
    return 1;
  }else{
    return 0;
  }
}

void push(struct Stack *stack ,int data){

//   printf("Top in push: %d \n", stack->top);
  stack->top++;
  if(isFULL(stack)){
    printf("Stack Overflow");
    return;
  }else{
    stack->arr[stack->top]=data;//yrd
  }
}

int pop(struct Stack *stack ){
    //if(stack->top>=0){
    //    int pop_item=stack->arr[stack->top];
    //    stack->top--;
    //    return pop_item;
    //}else{
    //    printf("Stack Underflow");
    //    return -1;
    //}

    if(isEmpty(stack)){
        printf("Stack Underflow");
        return -1;
    }else{
        int pop_item=stack->arr[stack->top];
        stack->top--;
        return pop_item;
    }

}

int peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty, cannot peek\n");
        return -1;
    }else{
        int peek=stack->arr[stack->top];
        return peek;
    }
}

void print(struct Stack *stack){
    while(stack->top>=0){
            char ch=stack->arr[stack->top];
        printf("%c ",ch);
        stack->top--;
    }
    return;
}


void push_string(char str[],struct Stack *stack){
    char ch;
//printf("IN push string: %d", stack->top);
   for(int i=0; str[i]!='\0'; i++){
      ch=str[i];
      push(stack,ch); //removed &
      //printf("%d", stack->top);

   }

   print(stack); //removed &

   return;

}
int main(){
    struct Stack stack;

    initialize(&stack);
    //char ch='a';
    //push(&stack,ch);
    //print(&stack);

    char str[MAX];
    scanf("%s",str);


    push_string(str,&stack);
    //intf("%d", stack.top);
    //print(&stack);

}
