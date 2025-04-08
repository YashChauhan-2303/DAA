#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];
int comparisons = 0;

int hash(int key) {
    return key % TABLE_SIZE;
}

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

void insert(int key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            printf("Hash Table is Full!\n");
            return;
        }
    }
    hashTable[index] = key;
}

int successfulSearch(int key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index] != EMPTY) {
        comparisons++;
        if (hashTable[index] == key)
            return index;

        index = (index + 1) % TABLE_SIZE;
        if (index == start)
            break;
    }
    return -1;
}

int unsuccessfulSearch(int key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index] != EMPTY) {
        comparisons++;
        if (hashTable[index] == key)
            return index;

        index = (index + 1) % TABLE_SIZE;
        if (index == start)
            break;
    }
    comparisons++; // one last check when it's empty
    return -1;
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != EMPTY)
            printf("%d -> %d\n", i, hashTable[i]);
        else
            printf("%d -> NULL\n", i);
    }
}

int main() {
    initTable();

    int keys[] = {23, 43, 13, 27, 88};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(keys[i]);
    }

    display();

    // Successful Search
    comparisons = 0;
    int key1 = 13;
    int pos1 = successfulSearch(key1);
    printf("\nSuccessful Search: Key = %d, Found at Index = %d\n", key1, pos1);
    printf("Key Comparisons: %d\n", comparisons);

    // Unsuccessful Search
    comparisons = 0;
    int key2 = 99;
    int pos2 = unsuccessfulSearch(key2);
    printf("\nUnsuccessful Search: Key = %d, Not Found\n", key2);
    printf("Key Comparisons: %d\n", comparisons);

    return 0;
}
