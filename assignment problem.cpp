#include <stdio.h>
#include <limits.h>

#define N 4

int cost[N][N] = {
    {10, 2, 8, 5},
    {3, 9, 6, 7},
    {7, 5, 3, 8},
    {9, 4, 6, 3}
};

int assignmentUtil(int u, int mask, int dp[], int n) {
    if (mask == (1 << n) - 1) return 0;
    
    if (dp[mask] != -1) return dp[mask];

    int minCost = INT_MAX;
    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v))) {
            int costVal = cost[u][v] + assignmentUtil(u + 1, mask | (1 << v), dp, n);
            if (costVal < minCost) minCost = costVal;
        }
    }

    return dp[mask] = minCost;
}

int main() {
    int dp[1 << N];
    for (int i = 0; i < (1 << N); i++) dp[i] = -1;

    printf("Minimum cost: %d\n", assignmentUtil(0, 0, dp, N));

    return 0;
}

