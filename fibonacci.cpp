#include <stdio.h>

int fibonacci(int n) {
  if (n <= 0) {
    printf("Input should be a positive integer");
    return -1;
  } else if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {
  int num_terms;
  printf("How many terms of the Fibonacci series would you like to generate? ");
  scanf("%d", &num_terms);
  for (int i = 1; i <= num_terms; i++) {
    printf("%d ", fibonacci(i));
  }
  printf("\n");
  return 0;
}

