#include <cs50.h>
#include <stdio.h>
#include <string.h> // for strcmp()

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");

    for (int i = 0, length = strlen(strings); i < length; ++i)
    {
        if (strcmp(strings[i], s) == 0) // strcmp() - compares two strings
        {
            printf("Found.\n");
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}