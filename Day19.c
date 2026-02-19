#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestPair(int arr[], int n) {
    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int minLeft = left, minRight = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            minLeft = left;
            minRight = right;
        }

        // Move pointers based on sum
        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", arr[minLeft], arr[minRight]);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findClosestPair(arr, n);

    return 0;
}
