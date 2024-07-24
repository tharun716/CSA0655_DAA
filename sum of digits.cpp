#include <stdio.h>
int sumOfDigits(int number) {
    int sum = 0;
    while (number != 0) {
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }
    return sum;
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = sumOfDigits(num);
    printf("Sum of digits of %d is %d\n", num, result);
    return 0;
}
