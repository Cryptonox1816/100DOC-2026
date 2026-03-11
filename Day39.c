#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // maximum heap size

int heap[MAX];
int heapSize = 0;

// Helper functions
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert element into heap
void insert(int x) {
    if (heapSize == MAX) {
        return; // Heap full
    }
    heap[heapSize] = x;
    int i = heapSize;
    heapSize++;

    // Bubble up
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
}

// Heapify (used in extractMin)
void heapify(int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// Extract minimum element
int extractMin() {
    if (heapSize <= 0) return -1;
    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapify(0);

    return root;
}

// Peek minimum element
int peek() {
    if (heapSize <= 0) return -1;
    return heap[0];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
