// Program that prints the minimum coins needed to make the given amount of change.

#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int change = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    do
    {
        // Prompt for change
        change = get_int("Change owed: ");

        // Check quarters
        if (change >= 25)
        {
            quarters = change / 25;
            change = change - quarters * 25;
        }

        // Check dimes
        if (change < 25 && change >= 10)
        {
            dimes = change / 10;
            change = change - dimes * 10;
        }

        // Check nickels
        if (change < 10 && change >= 5)
        {
            nickels = change / 5;
            change = change - nickels * 5;
        }

        // Check pennies
        if (change < 5 && change >= 1)
        {
            pennies = change;
        }

        // Calculate the amount of coins
        int amount = quarters + dimes + nickels + pennies;
        printf("%i\n", amount);
    }
    while (change < 0);

    return 0;
}

// 1. Prompt for change with 'get_int'
// 2. Calculate the amount of coins you need to give.
//      a. Calculate how many quarters (25) you need to give.
//      b. Calculate how many dimes (10) you need to give.
//      c. Calculate how many nickels (5) you need to give.
//      d. Calculate how many pennies (1) you need to give.
// 3. Print the sum.