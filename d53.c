#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct QueueNode {
    struct Node* node;
    int hd;
};

struct VerticalList {
    int hd;
    int nodes[100];
    int count;
};

struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node** q = (struct Node**)malloc(sizeof(struct Node*) * n);
    int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = q[f++];
        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) q[r++] = curr->left;
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) q[r++] = curr->right;
        }
    }
    return root;
}

void verticalOrder(struct Node* root, int n) {
    if (!root) return;

    struct VerticalList vLists[200]; 
    for(int i=0; i<200; i++) { vLists[i].count = 0; vLists[i].hd = i - 100; }

    struct QueueNode* q = (struct QueueNode*)malloc(sizeof(struct QueueNode) * n);
    int f = 0, r = 0;
    int min_hd = 0, max_hd = 0;

    q[r++] = (struct QueueNode){root, 0};

    while (f < r) {
        struct QueueNode curr = q[f++];
        int idx = curr.hd + 100;
        vLists[idx].nodes[vLists[idx].count++] = curr.node->data;
        
        if (curr.hd < min_hd) min_hd = curr.hd;
        if (curr.hd > max_hd) max_hd = curr.hd;

        if (curr.node->left) q[r++] = (struct QueueNode){curr.node->left, curr.hd - 1};
        if (curr.node->right) q[r++] = (struct QueueNode){curr.node->right, curr.hd + 1};
    }

    for (int i = min_hd + 100; i <= max_hd + 100; i++) {
        if (vLists[i].count > 0) {
            for (int j = 0; j < vLists[i].count; j++) {
                printf("%d ", vLists[i].nodes[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root, n);

    return 0;
}