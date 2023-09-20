#include<stdio.h>
#define MAXSIZE 20
char s[20];
int top=-1;

typedef enum{lparen,rparen,plus,minus,times,division,mod,eos,operand}precedence;

int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};

precedence get_token(char c){
    switch(c){
        case '(':
            return lparen;
        case ')':
            return rparen;
        case '+':
            return plus;
        case '-':
            return minus;
        case '*':
            return times;
        case '/':
            return division;
        case '%':
            return mod;
        case '#':
            return eos;
        default:
            return operand;
    }
}

void push(char ele)
{
    if(top==MAXSIZE-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        s[++top]=ele;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return '\0';
    }
    else
        return s[top--];
}
void postfix_eval(char postfix[]){
    int i=0;
    char op1,op2;
    precedence temp;
    while(postfix[i]!='\0'){
        temp=get_token(postfix[i]);
        if(temp==operand){
            push(postfix[i]-48);
        }
        else{
            op1=pop();
            op2=pop();
            switch(postfix[i]){
            case '+':
                push(op1+op2);
                break;
            case '-':
                push(op1-op2);
                break;
            case '*':
                push(op1*op2);
                break;
            case '/':
                push(op1/op2);
                break;
            case '%':
                push(op1%op2);
                break;
            }
        }
        i++;
    }
printf("result=%d",pop());
}
int main(){

    char arr[10],outp[20];
    int i;
    printf("enter postfix expression\n");
    scanf("%s",arr);
    postfix_eval(arr);
    return 0;
}
