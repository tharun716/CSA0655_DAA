#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
int solution[MAX_SIZE];
int num_solutions = 0;
void subsetSum(int set[], int subset[], int n, int subsetSize, int sum, int target, int index) {
    if (sum == target) {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
            solution[num_solutions++] = subset[i];
        }
        printf("\n");
        return;
    }
    for (int i = index; i < n; i++) {
        if (sum + set[i] <= target) {
            subset[subsetSize] = set[i];
            subsetSum(set, subset, n, subsetSize + 1, sum + set[i], target, i + 1);
        }
    }
}
void findSubsets(int set[], int n, int target) {
    int subset[MAX_SIZE]; 
    subsetSum(set, subset, n, 0, 0, target, 0);
}

int main() {
    int n, target;
    int set[MAX_SIZE];
    printf("Enter number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    findSubsets(set, n, target);
    printf("\nTotal number of solutions: %d\n", num_solutions);
    printf("Solution set: ");
    for (int i = 0; i < num_solutions; i++) {
        printf("%d ", solution[i]);
    }
    printf("\n");

    return 0;
}
