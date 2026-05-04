#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insertLevelOrder(struct Node** root, int arr[], int i, int n) {
    if (i < n) {
        if (arr[i] == -1) {
            *root = NULL;
            return;
        }
        struct Node* temp = createNode(arr[i]);
        *root = temp;
        insertLevelOrder(&((*root)->left), arr, 2 * i + 1, n);
        insertLevelOrder(&((*root)->right), arr, 2 * i + 2, n);
    }
}
void zigzagLevelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node** currentLevel = (struct Node**)malloc(100 * sizeof(struct Node*));
    struct Node** nextLevel = (struct Node**)malloc(100 * sizeof(struct Node*));
    int currentCount = 0, nextCount = 0;
    int leftToRight = 1;
    currentLevel[currentCount++] = root;
    while (currentCount > 0) {
        struct Node* node = currentLevel[--currentCount];
        printf("%d ", node->data);
        if (leftToRight) {
            if (node->left) {
                nextLevel[nextCount++] = node->left;
            }
            if (node->right) {
                nextLevel[nextCount++] = node->right;
            }
        } else {
            if (node->right) {
                nextLevel[nextCount++] = node->right;
            }
            if (node->left) {
                nextLevel[nextCount++] = node->left;
            }
        }
        if (currentCount == 0) {
            leftToRight = !leftToRight;
            struct Node** temp = currentLevel;
            currentLevel = nextLevel;
            nextLevel = temp;
            nextCount = 0;
        }
    }
    free(currentLevel);
    free(nextLevel);
}
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the level-order traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = NULL;
    insertLevelOrder(&root, arr, 0, n);
    printf("Zigzag level order traversal: ");
    zigzagLevelOrder(root);
    free(arr);
    return 0;
}