#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue structure for level order traversal
struct Queue {
    struct Node** arr;
    int front, rear, size;
    unsigned capacity;
};

// Function to create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

// Check if queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Enqueue operation
void enqueue(struct Queue* queue, struct Node* item) {
    if (queue->size == queue->capacity) return; // queue full
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size++;
}

// Dequeue operation
struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    struct Node* item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Function for Level Order Traversal
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue(100); // capacity chosen arbitrarily
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        struct Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(queue, current->left);

        if (current->right != NULL)
            enqueue(queue, current->right);
    }
}

int main() {
    // Constructing the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Level Order Traversal of the binary tree:\n");
    levelOrderTraversal(root);

    return 0;
}
