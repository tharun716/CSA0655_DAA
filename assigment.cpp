#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 4 
int findMinRow(int cost[N][N], bool assigned[N], int row) {
    int min = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (!assigned[j] && cost[row][j] < min) {
            min = cost[row][j];
        }
    }
    return min;
}
int findMinColumn(int cost[N][N], bool assigned[N], int col) {
    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (!assigned[i] && cost[i][col] < min) {
            min = cost[i][col];
        }
    }
    return min;
}
int calculateLowerBound(int cost[N][N], bool assigned[N]) {
    int lowerBound = 0;
    for (int i = 0; i < N; i++) {
        if (!assigned[i]) {
            lowerBound += findMinRow(cost, assigned, i);
        }
    }
    for (int j = 0; j < N; j++) {
        if (!assigned[j]) {
            lowerBound += findMinColumn(cost, assigned, j);
        }
    }
    return lowerBound;
}
void solveAssignment(int cost[N][N]) {
    int minCost = INT_MAX;
    int assignment[N];
    bool assigned[N] = { false };

    for (int i = 0; i < N; i++) {
        assignment[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        int minRow = INT_MAX;
        int minTask = -1;

        for (int j = 0; j < N; j++) {
            if (!assigned[j] && cost[i][j] < minRow) {
                minRow = cost[i][j];
                minTask = j;
            }
        }

        assignment[i] = minTask;
        assigned[minTask] = true;
        minCost += minRow;
    }

    printf("Minimum cost: %d\n", minCost);
    printf("Assignments:\n");
    for (int i = 0; i < N; i++) {
        printf("Agent %d is assigned to task %d\n", i, assignment[i]);
    }
}

int main() {
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 8, 3, 7},
        {5, 8, 4, 8},
        {7, 6, 9, 4}
    };

    solveAssignment(cost);

    return 0;
}
