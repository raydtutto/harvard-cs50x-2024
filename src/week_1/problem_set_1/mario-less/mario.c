// Prints a right-aligned pyramid with a height prompt by a user.

#include <cs50.h>
#include <stdio.h>

// Function declarations
void print_row_hash(int length);
void print_row_space(int length);

// Main program
int main(int argc, char *argv[])
{
    int height;

    do
    {
        // Prompt the user for the pyramid's height
        height = get_int("Height: ");

        // Print a pyramid of that height
        for (int i = 0; i < height; i++)
        {
            // Print spaces
            print_row_space(height - i - 1);
            // Print hashes "#"
            print_row_hash(i + 1);
            // New line
            printf("\n");
        }
    }
        // Keep to re-prompt the user if the input not greater than 0 or of another data type
    while (height <= 0);
}

// Function definitions

// Prints hashes "#"
void print_row_hash(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("#");
    }
}

// Prints spaces
void print_row_space(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf(" ");
    }
}

// 1. Prompt for height with 'get_int'
//      a. Re-prompt the user if the input not greater than 0 or of another data type.
// 2. For each row:
//      Depends on height of pyramid and row number:
//          a. Print spaces
//          b. Print hashes
//          c. Print a new line