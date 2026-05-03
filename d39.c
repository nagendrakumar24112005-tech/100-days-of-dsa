#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    if (size >= MAX) return;
    
    heap[size] = x;
    int curr = size;
    size++;

    while (curr > 0 && heap[(curr - 1) / 2] > heap[curr]) {
        swap(&heap[(curr - 1) / 2], &heap[curr]);
        curr = (curr - 1) / 2;
    }
}

void minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

void extractMin() {
    if (size <= 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    minHeapify(0);
}

void peek() {
    if (size <= 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[20];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    return 0;
}