#include <stdio.h>

int main() {
    int n, pos, x;
    scanf("%d", &n);

    int arr[n + 1];  // allocate space for n+1 elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos); // 1-based position
    scanf("%d", &x);   // element to insert

    // Shift elements to the right starting from the end
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x; // insert element at given position

    // Print updated array
    for (int i = 0; i <= n; i++) {
        printf("%d", arr[i]);
        if (i < n) printf(" ");
    }
    return 0;
}
