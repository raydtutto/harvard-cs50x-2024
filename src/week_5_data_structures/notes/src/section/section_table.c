#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define linked list
typedef struct node
{
    string phrase;
    struct node *next;
}
node;

// Array of alphabet characters
node *table[26];

int hash(string phrase);

int main(void)
{
    // Add items
    for (int i = 0; i < 3; ++i)
    {
        string phrase = get_string("Enter a new phrase: ");

        // Find phrase bucket
        int bucket = hash(phrase);
        printf("%s hashes to %i\n", phrase, bucket);
    }

    return 0;
}

// TODO: return the correct bucket for a given phrase
int hash(string phrase)
{
    return toupper(phrase[0]) - 'A';

    // `tolower` will be similar to `toupper`
    // return tolower(phrase[0]) - 'a';
}