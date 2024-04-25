#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    // Perform addition
    printf("%i\n", add(x, y)); // passing 'x' and 'y' as 'a' and 'b' from the 'add' function
}

int add(int a, int b) // return integer, takes two integers as input, use different names for variables
{
    return a + b;
}