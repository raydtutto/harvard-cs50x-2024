#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    bool is_prime = true;

    // Check not prime numbers
    if (number <= 1)
    {
        is_prime = false;
    }
    else
    {
        // Check for prime number
        for (int j = 2; j <= sqrt(number); j++)
        {
            if (number % j == 0)
            {
                is_prime = false;
                break;
            }
        }
    }

    return is_prime;
}