// A program that enables you to encrypt messages using Caesar’s cipher

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
void cipher_txt(string txt, int k);

// Main program
int main(int argc, string argv[])
{
    // Checks two argument counts
    if (argc != 2)
    {
        printf("./caesar key\n");
        return 1;
    }

    // Checks non-digits
    string key = argv[1];
    for (int i = 0, length = strlen(key); i < length; ++i)
    {
        if (!isdigit(key[i]))
        {
            // count++;
            printf("./caesar key\n");
            return 1;
        }
    }

    // Prompt for text
    string plaintxt = get_string("plaintext:  ");

    // Encrypts text with a key
    cipher_txt(plaintxt, atoi(key));

    return 0;
}

// Encrypts message
void cipher_txt(string txt, int k)
{
    char c;
    printf("ciphertext: ");

    for (int j = 0, length = strlen(txt); j < length; ++j)
    {
        if (isalpha(txt[j]))
        {
            // Rotate uppercase
            if (isupper(txt[j]))
            {
                c = (txt[j] - 'A' + k) % 26 + 'A';
                printf("%c", c);
            }
            // Rotate lowercase
            if (islower(txt[j]))
            {
                c = (txt[j] - 'a' + k) % 26 + 'a';
                printf("%c", c);
            }
        }
        else
        {
            printf("%c", txt[j]);
        }
    }

    printf("\n");
}