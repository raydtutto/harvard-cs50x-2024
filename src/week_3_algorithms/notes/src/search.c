#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n = get_int("Number: ");
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); ++i)
    {
        if (numbers[i] == n)
        {
            printf("Found.\n");
            return 0; // correct exit
        }
    }
    printf("Not found.\n");
    return 1; // exit with error
}