#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

// Enqueue function
void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
    printf("Push: %d\n", vertex);
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    int vertex = queue[front++];
    printf("Pop: %d\n", vertex);
    return vertex;
}

// BFS function
void bfs(int start, int vertices) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int current = dequeue();
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    int u, v;
    printf("Enter edges (format: u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // If undirected graph
    }

    int start;
    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("BFS traversal with Push/Pop:\n");
    bfs(start, vertices);

    return 0;
}
