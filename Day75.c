#include <stdio.h>
#include <stdlib.h>

// Structure to store prefix sum and its first occurrence index
typedef struct {
    int sum;
    int index;
} HashEntry;

int longestZeroSumSubarray(int arr[], int n) {
    // Allocate hash table (simple linear probing)
    int size = 2 * n;  // oversize to reduce collisions
    HashEntry *hash = (HashEntry *)malloc(size * sizeof(HashEntry));
    for (int i = 0; i < size; i++) {
        hash[i].sum = 999999; // sentinel for empty slot
        hash[i].index = -1;
    }

    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maxLen = i + 1;  // subarray from start
        }

        // Hash function
        int key = (prefixSum % size + size) % size;

        // Search in hash table
        int j = key;
        while (hash[j].sum != 999999 && hash[j].sum != prefixSum) {
            j = (j + 1) % size;
        }

        if (hash[j].sum == 999999) {
            // First occurrence of this prefix sum
            hash[j].sum = prefixSum;
            hash[j].index = i;
        } else {
            // Found earlier occurrence → subarray sum = 0
            int len = i - hash[j].index;
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }

    free(hash);
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestZeroSumSubarray(arr, n);
    printf("%d\n", result);  // Expected Output: 5

    return 0;
}
