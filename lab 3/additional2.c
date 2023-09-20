#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;


void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}


char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}


bool areParenthesesBalanced(char* expression) {
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (top < 0) {
                return false;
            }

            char topChar = pop();
            if ((expression[i] == ')' && topChar != '(') ||
                (expression[i] == ']' && topChar != '[') ||
                (expression[i] == '}' && topChar != '{')) {
                return false;
            }
        }
    }

    return (top == -1);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (areParenthesesBalanced(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}
