// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int indexes = hash(word);

    node *new_word = table[indexes];

    while (new_word != NULL)
    {
        if (strcasecmp(new_word->word, word) == 0)
        {
            return true;
        }
        new_word = new_word->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hashes = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++)
    {
        hashes = (hashes << 2) ^ toupper(word[i]);
    }
    return hashes % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    // Read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        strcpy(new_node->word, word);

        unsigned int index = hash(word);

        new_node->next = table[index];
        table[index] = new_node;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int count = 0;

    for (int i = 0; i < N; i++)
    {
        node *new_word = table[i];
        while (new_word != NULL)
        {
            count++;
            new_word = new_word->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *new_word = table[i];
        while (new_word != NULL)
        {
            node *ctr = new_word;
            new_word = new_word->next;
            free(ctr);
        }
    }
    return true;
}
