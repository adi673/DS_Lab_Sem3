#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
void main()
{
    int j;
    char s[MAX], b;
    {
        printf("Enter the String: \n");
        scanf("%s", s);
        for (j = 0;s[j] != '\0';j++)
        {
            b = s[j];
            push(b);
        }
            for (j = 0;j < (strlen(s) / 2);j++)
            {
                if (stack[top] == stack[front])
                {
                    pop();
                    front++;
                }
                else
                {
                    printf("%s is not a palindrome\n", s);
                    break;
                }
            }
            if ((strlen(s) / 2) == front)
                printf("%s is palindrome.\n", s);
            front = 0;
            top = -1;
    }
}

void push(char a)
{
    top++;
    stack[top] = a;
}

void pop()
{
    top--;
}
