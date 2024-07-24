#include <stdio.h>
int reverseNumber(int num, int rev) {
    if (num == 0) {
        return rev;
    }
    return reverseNumber(num / 10, rev * 10 + num % 10);
}
int main() {
    int num, reversed;   
    printf("Enter a number: ");
    scanf("%d", &num);   
    reversed = reverseNumber(num, 0);   
    printf("Reversed number is: %d\n", reversed);  
    return 0;
}
