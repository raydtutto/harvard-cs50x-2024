// Write a program to check if an array of characters is in alphabetical order.
// Assume the characters are all uppercase.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string phrase = get_string("Enter a phrase: ");

    for (int i = 0, length = strlen(phrase); i < length - 1; i++)
    {
        // Check if characters are not alphabetical
        if (phrase[i] > phrase[i + 1])
        {
            printf("Not in alphabetical order.");

            // Quit and end my program here
            return 0;
        }

    }
    printf("In alphabetical order.");

    return 0;
}