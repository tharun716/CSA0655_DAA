#include <stdio.h>
void printNumbers(int n) {
    if (n == 0) return; 
    printNumbers(n - 1); 
    printf("%d ", n); 
}
void printPattern(int current, int n) {
    if (current > n) return; 
    printNumbers(current); 
    printf("\n"); 
    printPattern(current + 1, n); 
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printPattern(1, n);
    return 0;
}
