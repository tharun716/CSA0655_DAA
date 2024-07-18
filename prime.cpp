#include <stdio.h>

int is_prime(int num, int div) {
  if (div == 1) {
    return 1;
  } else if (num % div == 0) {
    return 0;
  } else {
    return is_prime(num, div - 1);
  }
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  if (is_prime(num, num - 1)) {
    printf("%d is a prime number\n", num);
  } else {
    printf("%d is not a prime number\n", num);
  }
  return 0;
}

