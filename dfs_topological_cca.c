#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX], top = -1;

void dfs(int v, int vertices) {
    visited[v] = 1;
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i, vertices);
        }
    }
    stack[++top] = v;
}

void topologicalSortDFS(int vertices) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i])
            dfs(i, vertices);
    }

    printf("Topological Sort (DFS): ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

void topologicalSortKahn(int graph[MAX][MAX], int vertices) {
    int in_degree[MAX] = {0};

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (graph[i][j])
                in_degree[j]++;

    int queue[MAX], front = 0, rear = -1;

    for (int i = 0; i < vertices; i++)
        if (in_degree[i] == 0)
            queue[++rear] = i;

    int count = 0;
    printf("Topological Sort (Kahn): ");
    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);
        count++;

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i]) {
                in_degree[i]--;
                if (in_degree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    if (count != vertices)
        printf("\nCycle detected! No Topological Sort possible.\n");
    else
        printf("\n");
}

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    if (left && right) return root;

    return (left != NULL) ? left : right;
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    int n1 = 6, n2 = 4;
    struct Node* lca = findLCA(root, n1, n2);
    if (lca)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);
    else
        printf("LCA not found\n");

    return 0;
}
