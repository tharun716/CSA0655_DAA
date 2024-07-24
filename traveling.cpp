#include <stdio.h>
#include <limits.h>

#define N 4 
#define VISITED_ALL ((1 << N) - 1)
int tsp(int mask, int pos, int dist[N][N], int dp[1 << N][N]) {
    if (mask == VISITED_ALL) {
        return dist[pos][0]; 
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            ans = (ans < newAns) ? ans : newAns;
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int dp[1 << N][N];
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    int minCost = tsp(1, 0, dist, dp);

    printf("The minimum cost to visit all cities is: %d\n", minCost);

    return 0;
}
