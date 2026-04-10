#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
// Function to find the vertex with minimum distance
int minDistance(int dist[], int sptSet[], int vertices) {
   int min = INT_MAX, minIndex;
   for (int v = 0; v < vertices; v++) {
       if (!sptSet[v] && dist[v] < min) {
           min = dist[v];
           minIndex = v;
       }
   }
   return minIndex;
}
// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int dest, int vertices) {
   int dist[MAX_VERTICES];
   int sptSet[MAX_VERTICES];
   // Initialize distances and sptSet
   for (int i = 0; i < vertices; i++) {
       dist[i] = INT_MAX;
       sptSet[i] = 0;
   }
   dist[src] = 0;
   for (int count = 0; count < vertices - 1; count++) {
       int u = minDistance(dist, sptSet, vertices);
       sptSet[u] = 1;
       for (int v = 0; v < vertices; v++) {
           if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
               dist[v] = dist[u] + graph[u][v];
           }
       }
   }
   printf("Shortest Distance from %d to %d: %d\n", src, dest, dist[dest]);
}
int main() {
   int vertices;
   printf("Enter number of vertices: ");
   scanf("%d", &vertices);
   int graph[MAX_VERTICES][MAX_VERTICES];
   printf("Enter adjacency matrix (use 0 for no edge):\n");
   for (int i = 0; i < vertices; i++) {
       for (int j = 0; j < vertices; j++) {
           scanf("%d", &graph[i][j]);
       }
   }
   int src, dest;
   printf("Enter source and destination nodes: ");
   scanf("%d %d", &src, &dest);
   dijkstra(graph, src, dest, vertices);
   return 0;
}