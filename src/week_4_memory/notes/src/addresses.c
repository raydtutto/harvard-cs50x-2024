#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // int n = 50;

    // // Creates a pointer with the address of `n`
    // int *p = &n;

    // printf("%p\n", p); // `%p` with `p` - prints the address

    // // Prints an integer value
    // printf("%i\n", *p); // `*p` - go to the address and show what's inside

    string s = "HI!";
    printf("%s\n", s); // prints the value
    printf("\n");

    printf("%p\n", s); // prints an address
    printf("\n");

    printf("%p\n", &s[0]); // prints an address of the first character
    printf("%p\n", &s[1]); // prints an address of the second character
    printf("%p\n", &s[2]); // prints an address of the third character
    printf("%p\n", &s[3]); // prints an address of the forth NULL character

    // We can declare a string as a pointer without using cs50 lib
    char *s2 = "HI!"; // double quates around sequence of chars tells compiler to use the first char as an address,
                      // that's why there are no address operator `&` here.
    printf("%s\n", s2);
    printf("\n");

    //----------
    // Pointer arithmetic

    printf("%c", *s); // prints an address of the first character
    printf("%c", *(s + 1)); // prints an address of the first character
    printf("%c\n", *(s + 2)); // prints an address of the first character
    //----------
}