// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
typedef struct stack{
   char items[MAX_SIZE] ;
   int top;
}stack;

int precedence(char ch){
    if(ch=='*'|| ch=='/'){
        return 3;
    }
    if(ch=='+'|| ch=='-'){
        return 2 ;
    }
    return 0;
}
void initialize(stack* st){
    st->top=-1;
}

bool isEmpty(stack *st) {
 return st->top == -1;
}

bool isFull(stack *st) {
 return st->top == MAX_SIZE - 1;
}

void push(stack *st, char item) {
    if (isFull(st)) {
        printf("Stack overflow, cannot push %c\n", item);
        return;
    }
    st->top++;
    st->items[st->top] = item;
 }
 
 int pop(stack *st) {
    if (isEmpty(st)) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return an error value
    }
    int poppedItem = st->items[st->top];
    st->top--;
    return poppedItem;
}

int peek(stack *st) {
    if (isEmpty(st)) {
        printf("Stack is empty, cannot peek\n");
        return -1; // Return an error value
    }
    return st->items[st->top];
}


void infix_to_postfix(char ch[],stack* st,char postfix[]){
    int i,j=0;
    char symbol,next;
   
    for(i=0; ch[i]!='\0'; i++){
        symbol=ch[i];
        if(symbol=='('){
            push(st,symbol);
            
        }else if(symbol==')'){
            while(peek(st)!='('){
                char pop_it=pop(st);
                postfix[j++]=pop_it;
            }
            char pop_it=pop(st);
        }else if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'){
            while(!isEmpty(st) && precedence(peek(st)) >= precedence(symbol)) {
                postfix[j++]=pop(st);
            }
            push(st,symbol);
        }else{
            postfix[j++]=symbol;
        }
    }
    while(!isEmpty(st)){
        postfix[j++]=pop(st);
        
    }
    postfix[j]='\0';
}


int main() {
    char postfix[100];
    char infix[]={'7','+','(','9','-','5',')','*','*','2','\0'};
    stack st;
    initialize(&st);
    infix_to_postfix(infix,&st, postfix);
     printf("Postfix expression: %s\n", postfix);
    return 0;
}
