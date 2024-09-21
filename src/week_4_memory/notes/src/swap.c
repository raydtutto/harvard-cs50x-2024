#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);

    return 0;
}

void swap(int *a, int *b) { // get the addresses of integers as arguments
    int tmp = *a; // `tmp` is just a variable
    *a = *b;
    *b = tmp;
}