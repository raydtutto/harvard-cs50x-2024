#include <cs50.h>
#include <ctype.h> // for `toupper`
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    
    string t = s; // assumably copy one string to another
    
    t[0] = toupper(t[0]); // assumably capitalizes the letter
    
    printf("%s\n", s);
    printf("%s\n", t); // expecting the word from `s` but with capitalized first letter
    
    return 0;
}