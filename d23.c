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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

int main() {
    int n, m, val;
    struct ListNode *l1 = NULL, *l2 = NULL, *temp = NULL;

    if (scanf("%d", &n) == 1 && n > 0) {
        scanf("%d", &val);
        l1 = createNode(val);
        temp = l1;
        for (int i = 1; i < n; i++) {
            scanf("%d", &val);
            temp->next = createNode(val);
            temp = temp->next;
        }
    }

    if (scanf("%d", &m) == 1 && m > 0) {
        scanf("%d", &val);
        l2 = createNode(val);
        temp = l2;
        for (int i = 1; i < m; i++) {
            scanf("%d", &val);
            temp->next = createNode(val);
            temp = temp->next;
        }
    }

    struct ListNode* result = mergeTwoLists(l1, l2);

    while (result != NULL) {
        printf("%d%c", result->val, result->next ? ' ' : '\n');
        result = result->next;
    }

    return 0;
}