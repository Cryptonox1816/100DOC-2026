#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *tail = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input values and create linked list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);

        if (head == NULL) {
            head = temp;   // first node
            tail = temp;
        } else {
            tail->next = temp; // link new node
            tail = temp;
        }
    }

    // Traverse and print