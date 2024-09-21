#include <stdio.h>
#include <stdlib.h> // for `malloc()`

int main(void) {
    int *x = malloc(3 * sizeof(int)); // allocates x[]
    // `sizeof(int)` gets the size of an integer on any devices
    // `3 * sizeof(int)` creates an array of integers

    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    free(x); // deallocates x

    return 0;
}