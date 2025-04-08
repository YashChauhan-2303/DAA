#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// Utility function to get height
int height(struct Node* n) {
    return n ? n->height : 0;
}

// Utility function to get max
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Get Balance Factor
int getBalance(struct Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Right Rotate
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left Rotate
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert iteratively (with rebalancing)
struct Node* insert(struct Node* root, int key) {
    if (!root) return createNode(key);

    // Stack for backtracking
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;

    while (curr) {
        stack[++top] = curr;
        if (key < curr->key)
            curr = curr->left;
        else if (key > curr->key)
            curr = curr->right;
        else
            return root;  // No duplicates
    }

    // Insert the node
    struct Node* newNode = createNode(key);
    curr = stack[top];
    if (key < curr->key)
        curr->left = newNode;
    else
        curr->right = newNode;

    // Backtrack to fix balance
    while (top >= 0) {
        struct Node* node = stack[top--];
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && key < node->left->key) {
            if (top < 0)
                return rightRotate(node);
            if (stack[top]->left == node)
                stack[top]->left = rightRotate(node);
            else
                stack[top]->right = rightRotate(node);
        }

        // RR Case
        else if (balance < -1 && key > node->right->key) {
            if (top < 0)
                return leftRotate(node);
            if (stack[top]->left == node)
                stack[top]->left = leftRotate(node);
            else
                stack[top]->right = leftRotate(node);
        }

        // LR Case
        else if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            if (top < 0)
                return rightRotate(node);
            if (stack[top]->left == node)
                stack[top]->left = rightRotate(node);
            else
                stack[top]->right = rightRotate(node);
        }

        // RL Case
        else if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            if (top < 0)
                return leftRotate(node);
            if (stack[top]->left == node)
                stack[top]->left = leftRotate(node);
            else
                stack[top]->right = leftRotate(node);
        }
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// MAIN
int main() {
    struct Node* root = NULL;
    int data[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    printf("Inorder Traversal of AVL Tree:\n");
    inorder(root);
    return 0;
}
