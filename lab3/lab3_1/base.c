
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
    printf("Top is %d in initialize \n",stack->top);
}
int isFULL(struct Stack *stack){
  // printf("Top is %d in is full \n",stack->top);
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

void push(struct Stack **stack, int data){

  printf("Top is %d in starting 1 of push \n",(*stack)->top);
  (*stack)->top++;
 // printf("Top is %d in starting 2 of push \n",stack->top);
  if(isFULL(stack)){
    printf("Stack Overflow");
    return;
  }else{
    //printf("Came in else\n");
    (*stack)->arr[(*stack)->top]=data;
   // printf("Top is %d in push\n",stack->top);
    //printf("pushing done\n");
    return;
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

    while(stack->top>0){
        printf("Top is %d\n",stack->top);
        printf("stack element is %d\n ",stack->arr[stack->top]);
        stack->top--;
    }
    return;
}


void convert(int base, int n,struct Stack *stack){
    //printf("Entered inside convert\n");
    int N;
    printf("Top is %d in convert \n",stack->top);

    while(n!=0){
       // printf("Entered inside while loop\n");
        N=n%base;
        printf("Top is %d in convert 2 \n",stack->top);
        printf("pushing %d\n",N);
        push(&stack,N);

        n=n/base;
        printf("n is  %d\n",n);
    }
    print(&stack);
}


int main(){
    struct Stack stack;
    initialize(&stack);
    printf("Top is %d after inializion \n",stack.top);
     int base,n;
     printf("Enter the base");
     scanf("%d",&base);
     printf("Enter the number");
     scanf("%d",&n);
    // printf("Top is %d after inputing \n",stack.top);
     convert(base,n,&stack);
     //printf(&stack);




}

