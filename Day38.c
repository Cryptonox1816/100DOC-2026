#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int capacity;
    int front;
    int rear;
    int size;
} Deque;

// Initialize deque
Deque* createDeque(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->capacity = capacity;
    dq->arr = (int*)malloc(sizeof(int) * capacity);
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
    return dq;
}

// Utility functions
bool empty(Deque* dq) { return dq->size == 0; }
int size(Deque* dq) { return dq->size; }

// Core operations
void push_front(Deque* dq, int value) {
    if (dq->size == dq->capacity) {
        printf("Deque is full!\n");
        return;
    }
    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->arr[dq->front] = value;
    dq->size++;
    if (dq->rear == -1) dq->rear = dq->front;
}

void push_back(Deque* dq, int value) {
    if (dq->size == dq->capacity) {
        printf("Deque is full!\n");
        return;
    }
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->arr[dq->rear] = value;
    dq->size++;
}

void pop_front(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
    if (dq->size == 0) dq->rear = -1;
}

void pop_back(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    dq->size--;
    if (dq->size == 0) dq->rear = -1;
}

int front(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->front];
}

int back(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

// Additional operations
void clear(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

void reverse(Deque* dq) {
    if (dq->size <= 1) return;
    int tempArr[dq->size];
    for (int i = 0; i < dq->size; i++) {
        tempArr[i] = dq->arr[(dq->front + i) % dq->capacity];
    }
    for (int i = 0; i < dq->size; i++) {
        dq->arr[(dq->front + i) % dq->capacity] = tempArr[dq->size - 1 - i];
    }
}

void printDeque(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque: ");
    for (int i = 0; i < dq->size; i++) {
        printf("%d ", dq->arr[(dq->front + i) % dq->capacity]);
    }
    printf("\n");
}

// Demo
int main() {
    Deque* dq = createDeque(10);

    push_back(dq, 10);
    push_front(dq, 5);
    push_back(dq, 20);
    printDeque(dq); // 5 10 20

    printf("Front: %d\n", front(dq)); // 5
    printf("Back: %d\n", back(dq));   // 20
    printf("Size: %d\n", size(dq));   // 3

    pop_front(dq);
    pop_back(dq);
    printDeque(dq); // 10

    push_back(dq, 30);
    push_back(dq, 40);
    reverse(dq);
    printDeque(dq); // 40 30 10

    clear(dq);
    printDeque(dq); // empty

    free(dq->arr);
    free(dq);
    return 0;
}
