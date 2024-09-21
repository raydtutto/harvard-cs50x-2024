#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //----------
    // Compares integers
    // int i = get_int("i: ");
    // int j = get_int("j: ");
    //
    // if (i == j)
    // {
    //     printf("Same\n");
    // }
    // else
    // {
    //     printf("Different\n");
    // }
    //----------

    //----------
    // Compares string
    // string s = get_string("s: "); // string doesn't exist
    // string t = get_string("t: "); // string doesn't exist

    char *s = get_string("s: ");
    char *t = get_string("t: ");
    //
    // if (s == t) // compares the addresses of the first letters, not the letters themselves
    // {
    //     printf("Same\n");
    // }
    // else
    // {
    //     printf("Different\n");
    // }
    //----------

    //----------
    // Compares string with `strcmp` from the <string.h> lib
     // if (strcmp(s, t) == 0) // compares chars in string
     // {
     //     printf("Same\n");
     // }
     // else
     // {
     //     printf("Different\n");
     // }
    //----------

    //----------
    // Compares string with `strcmp` from the <string.h> lib
    printf("%p\n", s); // no need for `&` before `s`
    printf("%p\n", t); // prints address of the first letter
    //----------

    return 0;
}