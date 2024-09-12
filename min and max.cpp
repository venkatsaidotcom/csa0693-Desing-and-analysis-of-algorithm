#include <stdio.h>
int main() {
    int arr[] = {12, 5, 18, 1, 9, 22, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0, high = n - 1;
    int mid;
    int max, min;
    if (low == high) {
        max = min = arr[low];  
    } else if (high == low + 1) {  
        if (arr[low] > arr[high]) {
            max = arr[low];
            min = arr[high];
        } else {
            max = arr[high];
            min = arr[low];
        }
    } else {
        mid = (low + high) / 2;
        int leftMax = arr[low];
        int leftMin = arr[low];
        for (int i = low; i <= mid; i++) {
            if (arr[i] > leftMax)
                leftMax = arr[i];
            if (arr[i] < leftMin)
                leftMin = arr[i];
        }
        int rightMax = arr[mid + 1];
        int rightMin = arr[mid + 1];
        for (int i = mid + 1; i <= high; i++) {
            if (arr[i] > rightMax)
                rightMax = arr[i];
            if (arr[i] < rightMin)
                rightMin = arr[i];
        }
        max = (leftMax > rightMax) ? leftMax : rightMax;
        min = (leftMin < rightMin) ? leftMin : rightMin;
    }
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}

