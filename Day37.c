#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    if (size == MAX) return; // queue full
    pq[size++] = x;
}

// Delete element with highest priority (smallest value)
int delete() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex])
            minIndex = i;
    }

    int val = pq[minIndex];
    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
    return val;
}

// Peek element with highest priority (smallest value)
int peek() {
    if (size == 0) return -1;

    int minVal = pq[0];
    for (int i = 1; i < size; i++) {
        if (pq[i] < minVal)
            minVal = pq[i];
    }
    return minVal;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", delete());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
