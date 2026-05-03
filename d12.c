
/*
Problem: Write a program to check whether a given matrix is symmetric.
A matrix is said to be symmetric if it is a square matrix and is equal to its transpose.
*/

#include <stdio.h>

int main() {
int m, n;
if (scanf("%d %d", &m, &n) != 2) return 0;

int matrix[m][n];
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        scanf("%d", &matrix[i][j]);
    }
}

if (m != n) {
    printf("Not a Symmetric Matrix\n");
    return 0;
}



int isSymmetric = 1;
for (int i = 0; i < m; i++) {
    for (int j = 0; j < i; j++) {
        if (matrix[i][j] != matrix[j][i]) {
            isSymmetric = 0;
            break;
        }
    }
    if (!isSymmetric) break;
}

if (isSymmetric) {
    printf("Symmetric Matrix\n");
} else {
    printf("Not a Symmetric Matrix\n");
}

return 0;
}