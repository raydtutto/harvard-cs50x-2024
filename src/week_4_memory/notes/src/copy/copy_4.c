#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> // for `malloc` and `free`
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    
    char *t = malloc(strlen(s) + 1);

    if (t == NULL)
        return 1;

    strcpy(t, s);

    if (strlen > 0)
    {
        t[0] = toupper(t[0]);
    }
    
    printf("%s\n", s);
    printf("%s\n", t);

    free(t);
    
    return 0;
}