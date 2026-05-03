#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, int val) {
    struct Node* newNode = createNode(val);
    newNode->next = *top;
    *top = newNode;
}

void pop(struct Node** top) {
    if (*top == NULL) return;
    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
}

int main() {
    int n, m;
    struct Node* top = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(&top, val);
    }

    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        pop(&top);
    }

    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next ? " " : ""));
        temp = temp->next;
    }
    printf("\n");

    while (top != NULL) {
        pop(&top);
    }

    return 0;
}