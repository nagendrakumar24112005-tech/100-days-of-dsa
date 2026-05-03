/*
Problem: A system receives two separate logs of user arrival times from two different servers.
Each log is already sorted in ascending order. Your task is to create a single
chronological log that preserves the correct order of arrivals.
*/

#include <stdio.h>

int main() {
int p, q;

if (scanf("%d", &p) != 1) return 1;
int log1[p];
for (int i = 0; i < p; i++) {
    scanf("%d", &log1[i]);
}

if (scanf("%d", &q) != 1) return 1;
int log2[q];
for (int i = 0; i < q; i++) {
    scanf("%d", &log2[i]);
}

int i = 0;
int j = 0;
int first = 1;

while (i < p && j < q) {
    if (!first) printf(" ");
    
    if (log1[i] <= log2[j]) {
        printf("%d", log1[i]);
        i++;
    } else {
        printf("%d", log2[j]);
        j++;
    }
    first = 0;
}

while (i < p) {
    if (!first) printf(" ");
    printf("%d", log1[i]);
    i++;
    first = 0;
}

while (j < q) {
    if (!first) printf(" ");
    printf("%d", log2[j]);
    j++;
    first = 0;
}

printf("\n");
return 0;
}