#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void deleteKey(struct ListNode** head_ref, int key) {
    struct ListNode *temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->val == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->val != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    int n, key, val;
    struct ListNode *head = NULL, *tail = NULL;

    if (scanf("%d", &n) == 1 && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            struct ListNode* newNode = createNode(val);
            if (head == NULL) {
                head = newNode;
                tail = head;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    scanf("%d", &key);

    deleteKey(&head, key);

    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d%c", curr->val, curr->next ? ' ' : '\n');
        curr = curr->next;
    }

    return 0;
}