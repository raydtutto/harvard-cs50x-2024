// Program that checks the validity of a given credit card number.
// MasterCard uses 16-digit numbers, starts with 51, 52, 53, 54, or 55.
// American Express uses 15-digit numbers, starts with 34 or 37.
// Visa uses 13 and 16-digit numbers, starts with 4.

#include <cs50.h>
#include <stdio.h>

// Function declarations
int count(long card_number);
int cards_product_odd(long card_number);
int cards_product_even(long card_number);
void card_validation(long card_number);

// Main program
int main(int argc, char *argv[])
{
    // Prompt the card number
    long card = get_long("Number: ");

    // Calling a function that checks card validation
    card_validation(card);

    return 0;
}

// Function definitions

// Counts the amount of digits in the users card number
int count(long card_number)
{
    int count = 0;

    while (card_number > 0)
    {
        count++;
        card_number /= 10;
    }

    return count;
}

// Get and multiply the odd digit from the users card number
int cards_product_odd(long card_number)
{
    int digit, temp_digit, product;

    // Get the last digit
    digit = card_number % 10;

    // Multiply the last digit by 2
    temp_digit = digit * 2;

    // Get products’ digits if the product > 9
    if (temp_digit > 9)
    {
        // Get the second digit from product
        product = temp_digit % 10;
        int temp_product = product;

        // Get the first digit from product by removing the second digit
        temp_digit /= 10;
        product = temp_digit % 10;

        // Calculate the sum of digits
        int sum = product + temp_product;
        return sum;
    }
    else
    {
        return temp_digit;
    }
}

// Get the even digit from the users card number
int cards_product_even(long card_number)
{
    int digit, product;

    // Get the last digit
    digit = card_number % 10;

    // Get products’ digits if the product > 9
    if (digit > 9)
    {
        // Get the second digit from product
        product = digit % 10;
        int temp_product = product;

        // Get the first digit from product by removing the second digit
        digit /= 10;
        product = digit % 10;

        // Calculate the sum of digits
        int sum = product + temp_product;

        return sum;
    }
    else
    {
        return digit;
    }
}

// Checks the card validation
void card_validation(long card_number)
{
    int odd_result = 0, even_result = 0, temp_result = 0, result = 0;

    // Saves the card number
    long temp_user_card = card_number;

    // Calling a function that gets an amount of digits
    int digit_amount = count(card_number);

    if (digit_amount == 16)
    {
        // Leaves two first digits
        card_number /= 100000000000000;

        if (card_number == 51 || card_number == 52 || card_number == 53 || card_number == 54 ||
            card_number == 55)
        {
            // Returns original card number
            card_number = temp_user_card;

            // Get odd digits
            while (card_number > 0)
            {
                // Remove the last digit
                card_number /= 10;

                // Get the last digit
                temp_result = cards_product_odd(card_number);

                // Remove the last digit
                card_number /= 10;

                // Sum up the odd digits
                odd_result += temp_result;
            }

            // Get even digits
            while (temp_user_card > 0)
            {
                // Get the last digit
                temp_result = cards_product_even(temp_user_card);

                // Remove the last digit
                temp_user_card /= 100;

                // Sum up the even digits
                even_result += temp_result;
            }

            // Sum up the sum of odd and even digits
            result = odd_result + even_result;

            // Get the last digit
            int validation = result % 10;

            // Card validation
            if (validation == 0)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            card_number /= 10;

            if (card_number == 4)
            {
                card_number = temp_user_card;

                while (card_number > 0)
                {
                    // Remove the last digit
                    card_number /= 10;

                    // Get the last digit
                    temp_result = cards_product_odd(card_number);

                    // Remove the last digit
                    card_number /= 10;

                    // Sum up the products
                    odd_result += temp_result;
                }

                while (temp_user_card > 0)
                {
                    // Get the last digit
                    temp_result = cards_product_even(temp_user_card);

                    // Remove the last digit
                    temp_user_card /= 100;

                    even_result += temp_result;
                }

                result = odd_result + even_result;

                int validation = result % 10;

                if (validation == 0)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else if (digit_amount == 15)
    {
        card_number /= 10000000000000;

        if (card_number == 34 || card_number == 37)
        {
            card_number = temp_user_card;

            while (card_number > 0)
            {
                // Remove the last digit
                card_number /= 10;

                // Get the last digit
                temp_result = cards_product_odd(card_number);

                // Remove the last digit
                card_number /= 10;

                // Sum up the products
                odd_result += temp_result;
            }

            while (temp_user_card > 0)
            {
                // Get the last digit
                temp_result = cards_product_even(temp_user_card);

                // Remove the last digit
                temp_user_card /= 100;

                even_result += temp_result;
            }

            result = odd_result + even_result;

            int validation = result % 10;

            if (validation == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digit_amount == 13)
    {
        card_number /= 1000000000000;

        if (card_number == 4)
        {
            card_number = temp_user_card;

            while (card_number > 0)
            {
                // Remove the last digit
                card_number /= 10;

                // Get the last digit
                temp_result = cards_product_odd(card_number);

                // Remove the last digit
                card_number /= 10;

                // Sum up the products
                odd_result += temp_result;
            }

            while (temp_user_card > 0)
            {
                // Get the last digit
                temp_result = cards_product_even(temp_user_card);

                // Remove the last digit
                temp_user_card /= 100;

                even_result += temp_result;
            }

            result = odd_result + even_result;

            int validation = result % 10;

            if (validation == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// 1. Prompt for input.
// 2. Calculate checksum.
// 3. Check for card length and starting digits.
// 4. Print "AMEX", "MASTERCARD", "VISA" or "INVALID".