#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// adjacency list representation
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];   // array of adjacency lists
int visited[MAX]; // visited array

// function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// add edge (undirected graph)
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// recursive DFS
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, e, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;