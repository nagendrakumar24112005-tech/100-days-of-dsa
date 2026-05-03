/*
Problem: Write a program to check whether a given square matrix is an Identity Matrix.
An identity matrix is a square matrix in which all diagonal elements are 1 and
all non-diagonal elements are 0.
*/

#include <stdio.h>

int main() {
int n;
if (scanf("%d", &n) != 1) return 0;

int matrix[n][n];
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        scanf("%d", &matrix[i][j]);
    }
}



int isIdentity = 1;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i == j) {
            if (matrix[i][j] != 1) {
                isIdentity = 0;
                break;
            }
        } else {
            if (matrix[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
    }
    if (!isIdentity) break;
}

if (isIdentity) {
    printf("Identity Matrix\n");
} else {
    printf("Not an Identity Matrix\n");
}

return 0;
}