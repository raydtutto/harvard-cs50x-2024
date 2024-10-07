// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define PRIME 5

// Track the words
unsigned int count_words = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
// Initialize hash for DJB2 algorithm
const unsigned int N = 5381;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    // Ensure word exist
    if (word == NULL)
    {
        return false;
    }

    // Calculate the hash value
    unsigned int hash_value = hash(word);

    // Point to the head of the list
    node *trav = table[hash_value];

    // Traverse the linked list
    while (trav != NULL)
    {
        // Case-insensitive comparison
        if (strcasecmp(trav->word, word) == 0)
        {
            return true;
        }
        trav = trav->next;
    }

    // Word not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int result = 0;

    // Calculate hash value
    for (int i = 0; word[i] != '\0'; ++i)
    {
        // Spreading hash value with DJB2 algorithm, PRIME = 5
        // Result: 1.64 for holmes.txt
        result = ((result << PRIME) + result) + tolower(word[i]);

        // Spreading hash value with sdbm algorithm
        // Result: 1.65 for holmes.txt
        // result = tolower(word[i]) + (result << 6) + (result << 16) - result;

        // Spreading hash value with a prime number
        // Result: 1.67 for holmes.txt
        // result = result * 31 + (tolower(word[i]) - 'a');

        // Spreading hash value with lose-lose algorithm
        // Result: 3.01 for holmes.txt
        // result += tolower(word[i]);
    }

    // Hash value between 0 and N - 1
    if (result > (N - 1))
    {
        result = result % N;
    }

    return result;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // Open a file
    FILE *source = fopen(dictionary, "r");

    // Check the file
    if (source == NULL)
    {
        printf("Could not open file %s.\n", dictionary);
        return false;
    }

    // Allocate memory for buffer
    node *buffer = malloc(sizeof(node));

    // Read each word in the file
    while ((fscanf(source, "%s", buffer->word)) != EOF)
    {
        // Allocate memory for a new word
        node *new_word = malloc(sizeof(node));

        // Check the node
        if (new_word == NULL)
        {
            return false;
        }

        // Copy string to a new word and get hash value
        strcpy(new_word->word, buffer->word);
        int bucket = hash(new_word->word);

        // Point new word's next to the current head
        new_word->next = table[bucket];

        // Point an array to the new word
        table[bucket] = new_word;

        // Keep track of the words
        count_words++;

        printf("word: \"%s\", hash: %i\n", new_word->word, bucket);
    }

    // Close the file
    free(buffer);
    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *trav = NULL;
    node *tmp = NULL;

    // Traverse through the table
    for (int i = 0; i < N; ++i)
    {
        // Point to linked list
        trav = table[i];

        // Traverse and free the list
        while (trav != NULL)
        {
            tmp = trav;
            trav = trav->next;
            free(tmp);
        }
    }

    return true;
}