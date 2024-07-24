#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num, int i) {
    if (num <= 2) {
        return (num == 2) ? true : false;
    }
    if (num % i == 0) {
        return false;
    }
    if (i * i > num) {
        return true;
    }
    return isPrime(num, i + 1);
}
void generatePrimes(int current, int limit) {
    if (current > limit) {
        return;
    }
    if (isPrime(current, 2)) {
        printf("%d ", current);
    }
    generatePrimes(current + 1, limit);
}
int main() {
    int limit;
    printf("Enter the limit up to which to generate prime numbers: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d:\n", limit);
    generatePrimes(2, limit);
    return 0;
}
