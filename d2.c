#include <stdio.h>

int main() {
    int n, pos;

    if (scanf("%d", &n) != 1) return 1;

    int arr[n];

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    if (scanf("%d", &pos) != 1) return 1;

    int index = pos - 1;

    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    for (int i = 0; i < n - 1; i++) {
        printf("%d%s", arr[i], (i == n - 2) ? "" : " ");
    }
    printf("\n");

    return 0;
}