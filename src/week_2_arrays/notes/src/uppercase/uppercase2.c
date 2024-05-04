#include <cs50.h>
#include <ctype.h>
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
            // Make uppercase with function 'toupper'
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    return 0;
}