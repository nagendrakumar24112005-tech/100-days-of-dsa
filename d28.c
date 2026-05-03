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
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d%s", temp->data, (temp->next != head ? " " : ""));
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }

    if (head != NULL) {
        struct Node* curr = head;
        struct Node* nextNode;
        do {
            nextNode = curr->next;
            free(curr);
            curr = nextNode;
        } while (curr != head);
    }

    return 0;
}