// Program that checks the validity of a given credit card number.
// MasterCard uses 16-digit numbers, starts with 51, 52, 53, 54, or 55.
// American Express uses 15-digit numbers, starts with 34 or 37.
// Visa uses 13 and 16-digit numbers, starts with 4.

#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Amount of card's digits
int count_digits = 0;

// Function declarations
bool isAmex(const long card_number);
bool isMaster(const long card_number);
bool isVisa(const long card_number);
int every_digit(long card_number);
int multipy_and_sum(const int last_digit);
void check(const long card_number);

// Main program
int main(void)
{
    // Prompt the card number
    const long card = get_long("Number: ");

    // Sum every other digit
    const int sum_digit = every_digit(card);

    // Check the sum's last digit and amount of digits
    if (sum_digit % 10 != 0 || count_digits < 13 || count_digits > 16)
    {
        printf("INVALID\n");
        return 1;
    }

    // Check card
    check(card);
    return 0;
}

// Check for American Express
bool isAmex(const long card_number)
{
    // Find first two digits
    const int first_two_digits = card_number / pow(10, 13);

    // Check digits
    if ((count_digits == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return true;
    }
    return false;
}

// Check for MasterCard
bool isMaster(const long card_number)
{
    // Find first two digits
    const int first_two_digits = card_number / pow(10, 14);

    // Check digits
    if ((count_digits == 16) && (first_two_digits > 50 && first_two_digits < 56))
    {
        return true;
    }
    return false;
}

// Check for Visa
bool isVisa(const long card_number)
{
    if (count_digits == 13)
    {
        // Find the first digit
        const int first_digit = card_number / pow(10, 12);

        // Check digit
        if (first_digit == 4)
        {
            return true;
        }
    }
    else if (count_digits == 16)
    {
        // Find the first digit
        const int first_digit = card_number / pow(10, 15);
        // Check digit
        if (first_digit == 4)
        {
            return true;
        }
    }

    return false;
}

// Sum every digits
int every_digit(long card_number)
{
    int sum = 0;
    bool isAlternate = false;

    // Iterate through card digits
    while (card_number > 0)
    {
        // Sum alternate digits
        if (isAlternate)
        {
            // Find the last digit
            const int last_digit = card_number % 10;
            // Find the product of last digit
            const int product = multipy_and_sum(last_digit);
            // Sum products
            sum += product;
        }
        // Sum other digits
        else
        {
            // Find the last digit
            const int last_digit = card_number % 10;
            // Sum last digits
            sum += last_digit;
        }
        // Invert digit state
        isAlternate = !isAlternate;
        // Count card digits
        count_digits++;
        // Substract the last digit
        card_number = card_number / 10;
    }
    return sum;
}

int multipy_and_sum(const int last_digit)
{
    // Multiply last digit
    int multiply = last_digit * 2;
    int sum = 0;
    // Iterate through multiplied digit
    while (multiply > 0)
    {
        // Find the last digit
        const int last_digit_multuply = multiply % 10;
        // Sum digits
        sum += last_digit_multuply;
        // Substract the last digit
        multiply = multiply / 10;
    }
    return sum;
}

void check(const long card_number)
{
    if (isAmex(card_number))
    {
        printf("AMEX\n");
    }
    else if (isMaster(card_number))
    {
        printf("MASTERCARD\n");
    }
    else if (isVisa(card_number))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
