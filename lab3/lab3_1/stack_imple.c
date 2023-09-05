#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Stack{
 int arr[MAX];
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
  stack->top++;
  if(isFULL(stack)){
    printf("Stack Overflow");
    return;
  }else{
    stack->arr[stack->top]=data;
  }
}

int pop(struct Stack *stack ){


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
        printf("%d ",stack->arr[stack->top]);
        stack->top--;
    }
    return;
}

int main(){
    struct Stack stack;
    initialize(&stack);
    push(&stack,3);
    push(&stack,4);
    push(&stack,3);
    push(&stack,3);
    print(&stack);
}
