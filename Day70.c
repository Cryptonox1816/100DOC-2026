#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* newNode(int val) {
    if (val == -1) return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order input
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        Node* curr = queue[front++];

        // Left child
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[rear++] = curr->left;
        }
        // Right child
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[rear++] = curr->right;
        }
    }
    free(queue);
    return root;
}

// Zigzag traversal
void zigzagTraversal(Node* root) {
    if (!root) return;

    Node** queue = (Node**)malloc(1000 * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int leftToRight = 1; // flag

    while (front < rear) {
        int size = rear - front;
        int* level = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            Node* curr = queue[front++];
            level[i] = curr->data;

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        if (leftToRight) {
            for (int i = 0; i < size; i++) printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--) printf("%d ", level[i]);
        }

        leftToRight = !leftToRight; // flip direction
        free(level);
    }
    free(queue);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    Node* root = buildTree(arr, N);
    zigzagTraversal(root);

    return 0;
}
