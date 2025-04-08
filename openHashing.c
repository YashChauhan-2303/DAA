#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 200

struct Node {
    int key;
    struct Node* next;
};

struct Node* hashTable[100]; // Change this for different table sizes

int hash(int key, int tableSize) {
    return key % tableSize;
}

void insert(int key, int tableSize) {
    int index = hash(key, tableSize);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int successfulSearch(int key, int tableSize, int* comparisons) {
    int index = hash(key, tableSize);
    struct Node* current = hashTable[index];
    while (current) {
        (*comparisons)++;
        if (current->key == key)
            return 1;
        current = current->next;
    }
    return 0;
}

int unsuccessfulSearch(int key, int tableSize, int* comparisons) {
    int index = hash(key, tableSize);
    struct Node* current = hashTable[index];
    while (current) {
        (*comparisons)++;
        if (current->key == key)
            return 1;
        current = current->next;
    }
    return 0; // Always fail
}

void resetTable(int size) {
    for (int i = 0; i < size; i++) {
        hashTable[i] = NULL;
    }
}

int main() {
    int keys[MAX_KEYS];
    for (int i = 0; i < MAX_KEYS; i++)
        keys[i] = rand() % 1000;

    int tableSizes[] = {10, 20, 50, 100};
    int numKeys[] = {50, 100, 200};

    for (int t = 0; t < 4; t++) {
        int tableSize = tableSizes[t];
        for (int nk = 0; nk < 3; nk++) {
            int n = numKeys[nk];
            resetTable(tableSize);

            for (int i = 0; i < n; i++)
                insert(keys[i], tableSize);

            int successComp = 0;
            for (int i = 0; i < n; i++)
                successfulSearch(keys[i], tableSize, &successComp);

            int unsuccessComp = 0;
            for (int i = 0; i < n; i++)
                unsuccessfulSearch(keys[i] + 10000, tableSize, &unsuccessComp); // Ensure no match

            printf("Table Size = %d, Keys = %d, Load Factor = %.2f\n", tableSize, n, (float)n / tableSize);
            printf("Avg Successful Search Comparisons: %.2f\n", (float)successComp / n);
            printf("Avg Unsuccessful Search Comparisons: %.2f\n\n", (float)unsuccessComp / n);
        }
    }

    return 0;
}
