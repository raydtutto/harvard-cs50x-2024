#include <stdio.h>

//-------------------------------------------------
// Declare the function before the main program
//-------------------------------------------------

void meow(int n);

//-------------------------------------------------
// Main program
//-------------------------------------------------

int main(void)
{
    meow(8);

    return 0;
}

//-------------------------------------------------
// Define the function
//-------------------------------------------------

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}