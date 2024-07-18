#include <stdio.h>

int find_largest(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int main() {
  int arr[100];
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  printf("Enter the elements of the array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int largest = find_largest(arr, n);
  printf("The largest element of the array is: %d\n", largest);
  return 0;
}

