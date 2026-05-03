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

int main() {
    int n, k;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);
    k = k % n; 
    if (k == 0) {
        struct Node* temp = head;
        while (temp) {
            printf("%d%s", temp->data, (temp->next ? " " : ""));
            temp = temp->next;
        }
        printf("\n");
        return 0;
    }

    tail->next = head;

    int stepsToNewTail = n - k;
    struct Node* newTail = tail;
    for (int i = 0; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    head = newTail->next;
    newTail->next = NULL;

    struct Node* temp = head;
    while (temp) {
        printf("%d%s", temp->data, (temp->next ? " " : ""));
        temp = temp->next;
    }
    printf("\n");

    while (head) {
        struct Node* nextNode = head->next;
        free(head);
        head = nextNode;
    }

    return 0;
}