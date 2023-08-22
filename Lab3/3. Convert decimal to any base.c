#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int isEmpty(int top, int stack_arr[]);
void push(int x, int *top, int stack_arr[]);
int pop(int *top, int stack_arr[]);
void DecToBin(int num);
void DecToOct(int num);
void DecToHex(int num);

int main()
{
    int num,choice;
    printf("Enter an integer : ");
    scanf("%d",&num);
    printf("\nEnter the Base: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 2:
            printf("Binary Equivalent is : ");
            DecToBin(num);
            break;
        case 8:
            printf("Octal Equivalent is : ");
            DecToOct(num);
            break;
        case 16:
            printf("Hexadecimal Equivalent is : ");
            DecToHex(num);
            break;
        default:
            printf("\nInvalid base!!");
    }
    return 0;
}

void DecToBin(int num)
{
        int stack[MAX], top=-1, rem;
        while(num!=0)
        {
                rem = num%2;
                push(rem, &top, stack);
                num/=2;
        }
        while(top!=-1)
                printf("%d", pop(&top, stack));
        printf("\n");
}

void DecToOct(int num)
{
        int stack[MAX], top=-1, rem;
        while(num!=0)
        {
                rem = num%8;
                push(rem, &top, stack);
                num/=8;
        }
        while(top!=-1)
                printf("%d", pop(&top, stack));
        printf("\n");
}

void DecToHex(int num)
{
        int stack[MAX], top=-1, rem;
        while(num!=0)
        {
                rem = num%16;
                if (rem < 10)
                    rem = rem + 48;
                else
                    rem = rem + 55;
                push(rem, &top, stack);
                num/=16;
        }
        while(top!=-1)
                printf("%d", pop(&top, stack));
        printf("\n");
}

void push(int x, int *top, int stack_arr[])
{
        if(*top == (MAX-1))
                printf("Stack Overflow\n");
        else
        {
                *top=*top+1;
                stack_arr[*top] = x;
        }
}

int pop(int *top, int stack_arr[])
{
        int x;
        if(*top == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                x = stack_arr[*top];
                *top=*top-1;
        }
        return x;
}
