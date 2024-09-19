#include <stdio.h>

int main(void)
{
    int n = 50;

    // Creates a pointer with the address of `n`
    int *p = &n;

    printf("%p\n", p); // `%p` with `p` - prints the address

    // Prints an integer value
    printf("%i\n", *p); // `*p` - go to the address and show what's inside
}