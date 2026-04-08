#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // maximum number of vertices

// adjacency list representation
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];   // array of adjacency lists
int visited[MAX];
int stack[MAX];
int top = -1;

// utility to add edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// push to stack
void push(int v) {
    stack[++top] = v;
}

// pop from stack
int pop() {
    return stack[top--];
}

// DFS function
void DFS(int v) {
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
    push(v);  // push after visiting all neighbors
}

// Topological Sort
void topologicalSort(int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    printf("Topological Ordering: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int vertices, edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // initialize adjacency list
    for (int i = 0; i < vertices; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topologicalSort(vertices);

    return 0;
}
