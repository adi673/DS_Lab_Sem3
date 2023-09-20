#include<stdio.h>
#include<string.h>
#define MAXSIZE 20
char s[20][20];
int top=-1;

typedef enum{lparen,rparen,plus,minus,times,division,mod,eos,operand}precedence;

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

void push(char ele[])
{
    if(top==MAXSIZE-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        strcpy(s[++top],ele);
    }
}
char* pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return '\0';
    }
    else
        return (s[top--]);
}
void postfix2infix(char postfix[]){

    int op1,op2;
    char temp1[3],temp2[20];
    precedence temp;
    int i=0;
    while(postfix[i]!='\0'){
        temp=get_token(postfix[i]);
        temp1[0]=postfix[i];
        temp1[1]='\0';
        if(temp==operand){
            push(temp1);
        }
        else{
            op2=pop();
            op1=pop();
            strcpy(temp2,"(");
            strcat(temp2,op1);
            strcat(temp2,temp1);
            strcat(temp2,op2);
            strcat(temp2,")");
            push(temp2);

        }
        i++;
    }
    printf("%s",s);
}
int main(){

    char arr[20];
    int i;
    printf("enter postfix expression\n");
    scanf("%s",arr);
    postfix2infix(arr);
    return 0;
}
