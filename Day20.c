#include <stdio.h>
#include <stdlib.h>

// Hash map node
typedef struct Node {
    int sum;
    int count;
    struct Node* next;
} Node;

// Simple hash function
int hash(int sum, int size) {
    return (sum % size + size) % size;
}

// Insert or update sum in hash map
void insert(Node** table, int size, int sum) {
    int idx = hash(sum, size);
    Node* curr = table[idx];
    while (curr) {
        if (curr->sum == sum) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->count = 1;
    newNode->next = table[idx];
    table[idx] = newNode;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int size = 2 * n + 1; // hash table size
    Node** table = (Node**)calloc(size, sizeof(Node));

    int prefixSum = 0;
    insert(table, size, 0); // base case: prefix sum = 0
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        insert(table, size, prefixSum);
    }

    long long count = 0;
    for (int i = 0; i < size; i++) {
        Node* curr = table[i];
        while (curr) {
            if (curr->count > 1) {
                count += (long long)curr->count * (curr->count - 1) / 2;
            }
            curr = curr->next;
        }
    }

    printf("%lld\n", count);
    return 0;
}
