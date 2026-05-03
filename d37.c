#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x) {
    if (size >= MAX) return;

    int i;
    // Shift elements to the right to maintain descending order
    // Smallest element will be at pq[size-1]
    for (i = size - 1; i >= 0 && pq[i] < x; i--) {
        pq[i + 1] = pq[i];
    }
    pq[i + 1] = x;
    size++;
}

void delete() {
    if (size == 0) {
        printf("-1\n");
    } else {
        // The smallest element is at the end of the sorted array
        printf("%d\n", pq[--size]);
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[size - 1]);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[10];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}