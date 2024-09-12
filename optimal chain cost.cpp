#include <stdio.h>
#include <limits.h>

#define N 4

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int s[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int arr[] = {1, 2, 3, 4}; // Matrix dimensions
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum cost is %d\n", matrixChainOrder(arr, size));
    return 0;
}

