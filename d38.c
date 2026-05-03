#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct {
    struct Node *front;
    struct Node *rear;
    int count;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->count = 0;
    return dq;
}

void push_front(Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = dq->front;
    newNode->prev = NULL;

    if (dq->front == NULL) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->count++;
}

void push_back(Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->count++;
}

void pop_front(Deque* dq) {
    if (dq->front == NULL) return;
    struct Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    free(temp);
    dq->count--;
}

void pop_back(Deque* dq) {
    if (dq->rear == NULL) return;
    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }
    free(temp);
    dq->count--;
}

void display(Deque* dq) {
    struct Node* curr = dq->front;
    while (curr) {
        printf("%d%s", curr->data, (curr->next ? " " : ""));
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Deque* dq = createDeque();
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int choice, val;
        scanf("%d", &choice);
        switch(choice) {
            case 1: scanf("%d", &val); push_front(dq, val); break;
            case 2: scanf("%d", &val); push_back(dq, val); break;
            case 3: pop_front(dq); break;
            case 4: pop_back(dq); break;
        }
    }
    display(dq);
    return 0;
}