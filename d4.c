/*
Problem: Given an array of n integers, reverse the array in-place using
two-pointer approach. Shift elements from both ends and swap them.
*/

#include <stdio.h>

int main() {
int n;

if (scanf("%d", &n) != 1) return 1;

int arr[n];
for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) break;
}

int left = 0;
int right = n - 1;

while (left < right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    left++;
    right--;
}

for (int i = 0; i < n; i++) {
    printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
}
printf("\n");

return 0;
}