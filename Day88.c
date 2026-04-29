#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if cows can be placed with at least 'dist' distance
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1;  // place first cow at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
            if (count == k) return 1;  // all cows placed
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;  // minimum possible distance
    int high = stalls[n-1] - stalls[0];  // maximum possible distance
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;      // mid is possible, try for larger distance
            low = mid + 1;
        } else {
            high = mid - 1; // mid not possible, reduce distance
        }
    }

    printf("%d\n", ans);
    return 0;
}
