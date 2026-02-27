#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to calculate length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection point
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Advance longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++) head2 = head2->next;
    }

    // Traverse both lists together
    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1; // No intersection
}

int main() {
    int n, m, val;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // First list input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head1 = insertEnd(head1, val);
    }

    // Second list input
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        head2 = insertEnd(head2, val);
    }

    int result = findIntersection(head1, head2);
    if (result == -1)
        printf("No Intersection\n");
    else
        printf("%d\n", result);

    return 0;
}
