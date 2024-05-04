// Prints an adjacent pyramid with a height prompt by a user.

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
    }
        // Keep to re-prompt the user if the input not between 1 and 8
    while (height < 1 || height > 8);

    // Print a pyramid of that height
    for (int i = 0; i < height; i++)
    {
        // Print spaces
        print_row_space(height - i - 1);
        // Print hashes "#"
        print_row_hash(i + 1);
        // Print 2 spaces
        printf("  ");
        // Print hashes "#"
        print_row_hash(i + 1);
        // New line
        printf("\n");
    }

    return 0;
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