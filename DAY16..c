#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);   // Read size of array
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);   // Read array elements
    }

    int visited[n];   // To mark whether element is already counted
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) 
            continue;   // Skip if already counted

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;   // Mark duplicate as counted
            }
        }
        printf("%d:%d\n", arr[i], count);
    }

    return 0;
}
