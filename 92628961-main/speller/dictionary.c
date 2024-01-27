#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include "dictionary.h"
//okjhgfdsdsdsdsdsd
typedef struct node {
    char word[LENGTH];
    struct node *next;
} node;

const unsigned int N = 26;
node *table[N];
int totalWords = 0;
//ouijyhgfd
bool check(const char *word) {
    node *cursor = table[hash(word)];
    if (strcasecmp(cursor->word, word) == 0) {
        return true;
    }
    while (cursor->next != NULL) {
        cursor = cursor->next;
        if (strcasecmp(cursor->word, word) == 0) {
            return true;
        }
    }
    return false;
}
//mnbvcx
unsigned int hash(const char *word) {
    int n = (int) tolower(word[0]) - 97;
    return n;
}
//lkjhgfdsxaz
bool load(const char *dictionary) {
    FILE *file = fopen(dictionary, "r");
    char *dictWord = malloc(LENGTH);
    if (dictWord == NULL) {
        return false;
    }
    while (fscanf(file, "%s", dictWord) != EOF) {
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return false;
        }
        strcpy(n->word, dictWord);
        totalWords++;
        n->next = table[hash(dictWord)];
        table[hash(dictWord)] = n;
    }
    fclose(file);
    free(dictWord);
    return true;
}

unsigned int size(void) {
    return totalWords;
}
//uyygtf
bool unload(void) {
    node *tmp;
    node *cursor;
    for (int i = 0; i < N; i++) {
        if (table[i] == NULL) {
            continue;
        }
        cursor = table[i];
        tmp = cursor;
        while (cursor->next != NULL) {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
        free(cursor);
    }
    return true;
}
