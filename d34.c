#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    struct Node* top = NULL;

    // Read the entire line including spaces
    scanf("%[^\n]s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        // Skip spaces
        if (exp[i] == ' ') continue;

        if (isdigit(exp[i])) {
            // Handle multi-digit numbers if necessary, 
            // but for single digits:
            push(&top, exp[i] - '0');
        } else {
            // Operator encountered
            int val1 = pop(&top);
            int val2 = pop(&top);

            switch (exp[i]) {
                case '+': push(&top, val2 + val1); break;
                case '-': push(&top, val2 - val1); break;
                case '*': push(&top, val2 * val1); break;
                case '/': push(&top, val2 / val1); break;
            }
        }
    }

    printf("%d\n", pop(&top));
    return 0;
}