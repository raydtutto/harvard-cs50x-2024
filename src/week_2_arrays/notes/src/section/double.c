// Doubling up
// Create an array of integers in which each integer is 2 times the value of the previous integer.
// The first element is 1.
// Print the array, integer by integer.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = get_int("Enter a size: ");
    int sequence[size];
    sequence[0] = 1;
    printf("%i\n", sequence[0]);

    for (int i = 1; i < size; i++)
    {
        sequence[i] = sequence[i - 1] * 2;
        printf("%i\n", sequence[i]);
    }

    return 0;
}