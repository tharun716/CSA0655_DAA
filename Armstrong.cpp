#include <stdio.h>

int count_digits(int num) {
  if (num == 0) {
    return 0;
  } else {
    return 1 + count_digits(num / 10);
  }
}

int power(int num, int exp) {
  if (exp == 0) {
    return 1;
  } else {
    return num * power(num, exp - 1);
  }
}

int is_armstrong(int num) {
  int original_num = num;
  int digits = count_digits(num);
  int sum = 0;

  while (num != 0) {
    int digit = num % 10;
    sum += power(digit, digits);
    num /= 10;
  }

  if (sum == original_num) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  if (is_armstrong(num)) {
    printf("%d is an Armstrong number\n", num);
  } else {
    printf("%d is not an Armstrong number\n", num);
  }

  return 0;
}

