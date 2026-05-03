#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if ((rear + 1) % SIZE == front) {
        // Queue Full
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = val;
}

void dequeue() {
    if (front == -1) {
        // Queue Empty
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) return;
    
    int i = front;
    while (1) {
        printf("%d", queue[i]);
        if (i == rear) break;
        printf(" ");
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int n, m;
    
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(val);
    }
    
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        dequeue();
    }
    
    display();
    
    return 0;
}