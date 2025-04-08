#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int pushOrder[MAX];
int popOrder[MAX];
int pushIndex = 0;
int popIndex = 0;

void DFS(int vertex, int n) {
    visited[vertex] = 1;
    pushOrder[pushIndex++] = vertex;  // Push: vertex is first visited

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(i, n);
        }
    }

    popOrder[popIndex++] = vertex;  // Pop: finished exploring all neighbors
}

void dfs(int vertex,int n){
    visited[vertex]=1;
    pushOrder[pushIndex++] = vertex;
    for( int i=0;i<n;i++){
        if(graph[vertex][i] && !(visited[i])){
            dfs(i,n);
        }
    }
    popOrder[popIndex++] = vertex;
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex for DFS: ");
    int start;
    scanf("%d", &start);

    DFS(start, n);

    printf("\nPush order (DFS visit order): ");
    for (int i = 0; i < pushIndex; i++) {
        printf("%d ", pushOrder[i]);
    }

    printf("\nPop order (DFS backtrack order): ");
    for (int i = 0; i < popIndex; i++) {
        printf("%d ", popOrder[i]);
    }

    return 0;
}
