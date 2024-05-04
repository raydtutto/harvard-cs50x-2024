// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

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
        switch (s[i])
        {
            case 'a':
                printf("6");
                break;

            case 'e':
                printf("3");
                break;

            case 'i':
                printf("1");
                break;

            case 'o':
                printf("0");
                break;

            default:
                printf("%c", s[i]);
                break;
        }

    printf("\n");
}
