#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO

    // Gets the size of the string
    int length = strlen(input);

    // Return from the recursive function
    if (length <= 0)
    {
        return 0;
    }

    // Gets last_char
    char last_char = input[length - 1];

    // Gets the numeric value of the last char
    int last_int = last_char - '0';

    // Changes string length by moving the null terminator
    input[length - 1] = '\0';

    // Creates new input
    string new_input = input;

    return convert(new_input) * 10 + last_int;
}