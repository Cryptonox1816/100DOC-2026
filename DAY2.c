<<<<<<< HEAD
#include <stdio.h>

int main() {
    int n, pos;
    
    // Step 1: Read size
    scanf("%d", &n);
    
    int arr[n];
    
    // Step 2: Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Step 3: Read position to delete
    scanf("%d", &pos);
    
    // Step 4: Validate position
    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 0;
    }
    
    // Step 5: Shift elements left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Step 6: Print updated array
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
=======
#include <stdio.h>

int main() {
    int n, pos;
    
    // Step 1: Read size
    scanf("%d", &n);
    
    int arr[n];
    
    // Step 2: Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Step 3: Read position to delete
    scanf("%d", &pos);
    
    // Step 4: Validate position
    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 0;
    }
    
    // Step 5: Shift elements left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Step 6: Print updated array
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
>>>>>>> f097833c96f932be43c9e4ed7f5ac51f6f5a5bfc
