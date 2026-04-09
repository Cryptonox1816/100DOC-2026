#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue structure for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->rear < q->front;
}

// Enqueue element
void enqueue(Queue *q, int value) {
    if (q->rear < MAX_VERTICES - 1) {
        q->items[++q->rear] = value;
    } else {
        printf("Queue overflow!\n");
        exit(EXIT_FAILURE);
    }
}

// Dequeue element
int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->items[q->front++];
    } else {
        printf("Queue underflow!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to perform Kahn's Algorithm for Topological Sort
void topologicalSort(int adj[MAX_VERTICES][MAX_VERTICES], int V) {
    int inDegree[MAX_VERTICES] = {0};
    Queue q;
    initQueue(&q);

    // Step 1: Calculate in-degree of each vertex
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                inDegree[v]++;
            }
        }
    }

    // Step 2: Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    int count = 0; // Count of visited vertices
    int topoOrder[MAX_VERTICES];

    // Step 3: Process vertices in queue
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        topoOrder[count++] = u;

        // Decrease in-degree of all adjacent vertices
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                if (--inDegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != V) {
        printf("Error: Graph contains a cycle. Topological sort not possible.\n");
        return;
    }

    // Step 5: Print topological order
    printf("Topological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topoOrder[i]);
    }
    printf("\n");
}

int main() {
    int V, E;
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    if (scanf("%d", &V) != 1 || V <= 0 || V > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return EXIT_FAILURE;
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &E) != 1 || E < 0) {
        printf("Invalid number of edges.\n");
        return EXIT_FAILURE;
    }

    printf("Enter edges (u v) for directed graph (0-based indexing):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2 || u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid edge input.\n");
            return EXIT_FAILURE;
        }
        adj[u][v] = 1; // Directed edge from u to v
    }

    topologicalSort(adj, V);

    return 0;
}
