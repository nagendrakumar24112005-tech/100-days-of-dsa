/*Problem: A secret system stores code names in forward order. To display them
in mirror format, you must transform the given code name so that its
characters appear in the opposite order.
*/

#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
int left = 0;
int right = strlen(str) - 1;
char temp;

while (left < right) {
    temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    
    left++;
    right--;
}
}

int main() {
char codeName[1001];

if (scanf("%1000s", codeName) != 1) return 0;

reverseString(codeName);

printf("%s\n", codeName);

return 0;
}