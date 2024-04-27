// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    // Calculating tax amount
    tax = tax / 100 * bill;

    // Sum up bill and tax
    bill = bill + tax;

    // Convert int "tip" to float
    float tip_amount = (float) tip;

    // Get the tip amount
    tip_amount = tip_amount / 100 * bill;

    // Sum up bill and tip
    float result = (bill + tip_amount) / 2;

    return result;
}

// 1. Apply tax to the bill amount
// 2. Convert int "tip" to float
// 3. Calculating the tip
// 4. Return half of the full amount (amount + tax + tip)