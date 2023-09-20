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
void infix2postfix(char infix[],char postfix[]){
    int i=0,j=0;
    precedence temp;
    push('#');
    while(infix[i]!='\0'){
        temp=get_token(infix[i]);
        if(temp==operand)
            postfix[j++]=infix[i];
        else if (temp==rparen){
            while(s[top]!='('){
                postfix[j++]=pop();}
                pop();}

        else {
            while(icp[temp]<=isp[get_token(s[top])])

                {postfix[j++]=pop();}
                push(infix[i]);

        }
        i++;
    }
    while(top!=0){
    postfix[j++]=pop();
    }
}
int main(){

    char arr[10],outp[20];
    int i;
    printf("enter infix expression\n");
    scanf("%s",arr);
    infix2postfix(arr,outp);
    printf("postfix expression is\n%s",outp);
    return 0;
}
