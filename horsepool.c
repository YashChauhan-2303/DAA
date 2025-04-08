#include <stdio.h>
#include <string.h>
#define SIZE 256 // Number of ASCII characters

int shiftTable[SIZE];
int comparisons = 0;

// Function to create shift table
void buildShiftTable(char pattern[], int m) {
    for (int i = 0; i < SIZE; i++) {
        shiftTable[i] = m; // Default shift
    }
    for (int i = 0; i < m - 1; i++) {
        shiftTable[(unsigned char)pattern[i]] = m - 1 - i;
    }
}

// Horspool String Matching
int horspoolSearch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    buildShiftTable(pattern, m);

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
            comparisons++;
        }

        if (k == m) {
            return i - m + 1; // Match found
        } else {
            comparisons++;
            i += shiftTable[(unsigned char)text[i]];
        }
    }
    return -1; // No match
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    comparisons = 0;
    int pos = horspoolSearch(text, pattern);

    if (pos != -1) {
        printf("Pattern found at position: %d\n", pos);
        printf("Number of comparisons (successful): %d\n", comparisons);
    } else {
        printf("Pattern not found.\n");
        printf("Number of comparisons (unsuccessful): %d\n", comparisons);
    }

    return 0;
}
