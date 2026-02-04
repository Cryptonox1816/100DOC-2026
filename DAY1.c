#include <stdio.h>

int main() {
    int n, pos, x;
    
    // Step 1: Input size
    scanf("%d", &n);
    
    int arr[100]; // assuming max size 100
    
    // Step 2: Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Step 3: Input position and element
    scanf("%d", &pos);
    scanf("%d", &x);
    
    // Step 4: Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Step 5: Insert element
    arr[pos - 1] = x;
    
    // Step 6: Print updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
