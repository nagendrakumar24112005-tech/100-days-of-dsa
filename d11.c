/*
Problem: Write a program to perform addition of two matrices having the same dimensions.
The sum of two matrices is obtained by adding corresponding elements of the matrices.
*/

#include <stdio.h>

int main() {
int m, n;
if (scanf("%d %d", &m, &n) != 2) return 0;

int matrix1[m][n];
int matrix2[m][n];

for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        scanf("%d", &matrix1[i][j]);
    }
}

for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        scanf("%d", &matrix2[i][j]);
    }
}



for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        printf("%d%s", matrix1[i][j] + matrix2[i][j], (j == n - 1) ? "" : " ");
    }
    printf("\n");
}

return 0;
}