#include "cs50.h"
#include <stdio.h>

// You can declare a global variable that will in scope to every function in this file
//const int N = 3;

int main(void)
{
    // Common way to name constant integers is capitalized it
    const int N = 3;
    int scores[N];

//  Gives you an array with values inside
//  int scores = {72, 73, 33};

    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / (float) N);

    return 0;
}