#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void countWordFrequencies(char *paragraph) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS] = {0};
    int wordCount = 0;

    char *token = strtok(paragraph, " \n\t");
    while (token != NULL) {
        toLowerCase(token);
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[wordCount], token);
            count[wordCount]++;
            wordCount++;
        }
        token = strtok(NULL, " \n\t");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }
}

int main() {
    char paragraph[10000];

    printf("Enter a paragraph (end input with Ctrl+D):\n");
    // Read paragraph input from user
    // Note: fgets will only read a single line at a time
    // Use multiple fgets calls if you need to read multi-line input.
    if (fgets(paragraph, sizeof(paragraph), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    countWordFrequencies(paragraph);

    return 0;
}
