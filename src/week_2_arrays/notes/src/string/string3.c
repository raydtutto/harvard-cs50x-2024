#include <cs50.h>
#include <stdio.h>
#include <string.h> // for 'strlen'

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");

    // In initialization, we set the function's result to int 'n'
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}