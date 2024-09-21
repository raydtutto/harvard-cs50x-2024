#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> // for `malloc` and `free`
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    
    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n = strlen(s); i <= n; ++i) // `i <= n` copies all four chars with the last `\0`
    {
        t[i] = s[i];
    }

    if (strlen > 0)
    {
        t[0] = toupper(t[0]);
    }
    
    printf("%s\n", s);
    printf("%s\n", t);
    
    return 0;
}