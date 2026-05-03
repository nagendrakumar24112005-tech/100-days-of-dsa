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

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

int main() {
    int n, m;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head1) head1 = tail1 = newNode;
        else { tail1->next = newNode; tail1 = newNode; }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head2) head2 = tail2 = newNode;
        else { tail2->next = newNode; tail2 = newNode; }
    }

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1, *ptr2 = head2;

    int diff = abs(len1 - len2);
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++) ptr2 = ptr2->next;
    }

    int found = 0;
    while (ptr1 && ptr2) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            found = 1;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (!found) printf("No Intersection\n");

    return 0;
}