#include <stdio.h>
#include <limits.h>
void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    if (low == high) {
        if (*max < arr[low]) {
            *max = arr[low];
        }
        if (*min > arr[low]) {
            *min = arr[low];
        }
        return;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            if (*max < arr[high]) {
                *max = arr[high];
            }
            if (*min > arr[low]) {
                *min = arr[low];
            }
        } else {
            if (*max < arr[low]) {
                *max = arr[low];
            }
            if (*min > arr[high]) {
                *min = arr[high];
            }
        }
        return;
    }
    int mid = (low + high) / 2;
    findMaxMin(arr, low, mid, max, min);
    findMaxMin(arr, mid + 1, high, max, min);
}
int main() {
    int arr[] = {3, 5, 1, 8, 4, 2, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = INT_MIN;
    int min = INT_MAX;
    findMaxMin(arr, 0, n - 1, &max, &min);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    return 0;
}
