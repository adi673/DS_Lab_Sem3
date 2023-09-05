#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

void push(struct Stack *stack, char data){

  //printf("Top in push: %d \n", stack->top);
  stack->top++;
  if(isFULL(stack)){
    printf("Stack Overflow");
    return;
  }else{
    stack->arr[stack->top]=data;
  }
}

char pop(struct Stack *stack ){

    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        char ch='-1';
        return ch;
    }else{
        int pop_item=stack->arr[stack->top];
        stack->top--;
        return pop_item;
    }

}

char peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty, cannot peek\n");
        return -1;
    }else{
        char peek=stack->arr[stack->top];
        return peek;
    }
}

void print(struct Stack *stack){
    while(stack->top>=0){
        printf("%c ",stack->arr[stack->top]);
        stack->top--;
    }
    return;
}


bool check_palindrome(char str[], struct Stack *stack){
    char ch;
    int len=strlen(str);

    int mid=len/2;
    if(len%2==0){
        for(int i=0; i<=mid-1; i++){
            ch=str[i];
            push(stack,ch);
        }
        for(int i=mid;str[i]!='\0';i++){
            char ch=pop(stack);
            if(ch!=str[i]){
                return false;
            }
        }
        return true;
    }else if(len%2==1){
        for(int i=0; i<=mid-1; i++){
            ch=str[i];
            push(stack,ch);
        }
        for(int i=mid+1;str[i]!='\0';i++){
            char ch=pop(stack);
            if(ch!=str[i]){
                return false;
            }
        }
        return true;
   }



}
int main(){
    struct Stack stack;
    initialize(&stack);
    char str[MAX];
     printf("Given string\n");
    gets(str);
    if(check_palindrome(str,&stack)){
        printf("Given string is palindrome");
    }else{
        printf("Given string is not palindrome");
    }


}

