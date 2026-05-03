#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX];
    scanf("%s", infix);

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            printf("%c", c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", pop());
            }
            pop(); 
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
    }

    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}