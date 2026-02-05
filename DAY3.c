<<<<<<< HEAD
#include <stdio.h>

int main() {
    int n, k, i, comparisons = 0;
    
    // Input size
    scanf("%d", &n);
    int arr[n];
    
    // Input array
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input key
    scanf("%d", &k);
    
    // Linear search
    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", comparisons);
            return 0; // exit program after finding
        }
    }
    
    // If not found
    printf("Not Found\n");
    printf("Comparisons = %d\n", comparisons);
    
    return 0;
}
=======
#include <stdio.h>

int main() {
    int n, k, i, comparisons = 0;
    
    // Input size
    scanf("%d", &n);
    int arr[n];
    
    // Input array
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input key
    scanf("%d", &k);
    
    // Linear search
    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", comparisons);
            return 0; // exit program after finding
        }
    }
    
    // If not found
    printf("Not Found\n");
    printf("Comparisons = %d\n", comparisons);
    
    return 0;
}
>>>>>>> f097833c96f932be43c9e4ed7f5ac51f6f5a5bfc
