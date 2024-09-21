#include <stdio.h>

int main(void) {
    int n; // declares an integer where we want to put user's input
    printf("n: ");
    scanf("%i", &n); // passing by reference
    printf("\n");

    printf("n = %i\n", n);

    return 0;
}