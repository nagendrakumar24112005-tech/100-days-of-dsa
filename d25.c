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

int countOccurrences(struct ListNode* head, int key) {
    int count = 0;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        if (curr->val == key) {
            count++;
        }
        curr = curr->next;
    }
    
    return count;
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

    if (scanf("%d", &key) == 1) {
        printf("%d\n", countOccurrences(head, key));
    }

    return 0;
}