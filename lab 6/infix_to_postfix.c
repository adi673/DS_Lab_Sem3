#include<stdio.h>
#include<stdlib.h>
#  define MAXSIZE 20
char s[20],rev[20];
int top=-1;

typedef enum{lparen,rparen,plus,minus,times,division,mod,eos,operand}precedence;

int isp[]={19,0,12,12,13,13,13,0};
int icp[]={19,20,12,12,13,13,13,0};

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
void infix2prefix(char infix[],char prefix[]){
    int i=strlen(infix)-1,j=0;
    precedence temp;
    push('#');
    while(i>=0){
        temp=get_token(infix[i]);
        if(temp==operand)
            prefix[j++]=infix[i];
        else if (temp==lparen){
            while(s[top]!=')'){
                prefix[j++]=pop();}
                pop();}

        else {
            while(icp[temp]<isp[get_token(s[top])])

                {prefix[j++]=pop();}
                push(infix[i]);

        }
        i--;
    }
    while(top!=0){
    prefix[j++]=pop();
    }
    printf("%s=prefix expression",strrev(prefix));
}
int main(){

    char arr[10],outp[20];
    int i;
    printf("enter infix expression\n");
    scanf("%s",arr);
    infix2prefix(arr,outp);
    return 0;
}

