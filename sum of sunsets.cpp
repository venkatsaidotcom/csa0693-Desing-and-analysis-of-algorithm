#include <stdio.h>

#define N 4

int subsetSum(int arr[], int n, int sum, int currentSum, int start) {
    if (currentSum == sum) return 1;
    if (start == n || currentSum > sum) return 0;

    // Include current element
    if (subsetSum(arr, n, sum, currentSum + arr[start], start + 1)) return 1;
    
    // Exclude current element
    if (subsetSum(arr, n, sum, currentSum, start + 1)) return 1;

    return 0;
}

int main() {
    int arr[N] = {3, 34, 4, 12};
    int sum = 9;

    if (subsetSum(arr, N, sum, 0, 0))
        printf("Subset with sum %d exists\n", sum);
    else
        printf("Subset with sum %d does not exist\n", sum);

    return 0;
}

