#include <stdio.h>

// Recursive function to compute Fibonacci
int fib(int n) {
    if (n == 0) return 0;   // base case
    if (n == 1) return 1;   // base case
    return fib(n - 1) + fib(n - 2);  // recursive relation
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", fib(n));

    return 0;
}
