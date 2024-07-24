#include <stdio.h>
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}
int main() {
    int arr[] = {12, 34, 45, 21, 9, 38};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the number to search: ");
    scanf("%d", &key);
    int index = linearSearch(arr, n, key);
    if (index != -1) {
        printf("%d found at index %d\n", key, index);
    } else {
        printf("%d not found in the array\n", key);
    }
    return 0;
}
