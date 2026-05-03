
/*
Problem: Given a sorted array of n integers, remove duplicates in-place.
Print only unique elements in order.
*/

#include <stdio.h>

int main() {
int n;

if (scanf("%d", &n) != 1) return 1;
if (n <= 0) return 0;

int arr[n];
for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
}

int j = 0; 
for (int i = 1; i < n; i++) {
    if (arr[i] != arr[j]) {
        j++;
        arr[j] = arr[i];
    }
}

for (int i = 0; i <= j; i++) {
    printf("%d%s", arr[i], (i == j) ? "" : " ");
}
printf("\n");

return 0;
}