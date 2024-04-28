#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before:  ");
    printf("After: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If lowercase
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // Make uppercase
            printf("%c", s[i] - ('a' - 'A'));
//          printf("%c", s[i] - 32); // 32 - difference between 97 'a' and 65 'A'
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    return 0;
}