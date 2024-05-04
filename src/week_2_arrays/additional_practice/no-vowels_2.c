// Practice with two-dimensional array

#include <cs50.h>
#include <stdio.h>
#include <string.h>

void replace(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    replace(argv[1]);

    return 0;
}

// 'a' becomes '6', 'e' becomes '3', 'i' becomes '1',
// 'o' becomes '0' and 'u' does not change
void replace(string s)
{
    static const int letterLen =4;
    static int letters[4][2] = {
            {'a', 6},
            {'e', 3},
            {'i', 1},
            {'o', 0}
    };

    for (int i = 0, length = strlen(s); i < length; ++i)
    {
        bool found = false;
        for (int j = 0; j < letterLen; ++j)
            if (s[i] == letters[j][0]) {
                printf("%i", letters[j][1]);
                found = true;
                break;
            }
        if (found == false)
            printf("%c", s[i]);
    }

    printf("\n");
}
