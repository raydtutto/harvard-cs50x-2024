from cs50 import get_string

# Make a list from a card number
credit_card = list()

# Amount of digits
count_digits = 0


# Check for American Express
def isAmex():
    global count_digits
    first_two_digits = int(''.join(map(str, credit_card[:2])))
    if count_digits == 15 and (first_two_digits == 34 or first_two_digits == 37):
        return True
    return False


# Check for Mastercard
def isMaster():
    global count_digits
    if count_digits == 16 and 50 < int(''.join(map(str, credit_card[:2]))) < 56:
        return True
    return False


# Check for Visa
def isVisa():
    global count_digits
    if count_digits == 13 or count_digits == 16:
        if credit_card[0] == 4:
            return True
    return False


# Check the type of a card
def check():
    if isAmex():
        print("AMEX")
    elif isMaster():
        print("MASTERCARD")
    elif isVisa():
        print("VISA")
    else:
        print("INVALID")


# Multiply and sum
def multiply_and_sum(last_digit):
    multiply = last_digit * 2
    sum = 0

    while multiply > 0:
        last_digit_multiply = multiply % 10
        sum = sum + last_digit_multiply
        multiply = multiply // 10

    return sum


# Sum digits
def sum_every_digit():
    global count_digits
    sum = 0
    isAlternate = False
    temp_card = credit_card.copy()

    while len(temp_card) > 0:
        if isAlternate:
            last_digit = temp_card[-1]
            product = multiply_and_sum(last_digit)
            sum = sum + product
        else:
            last_digit = temp_card[-1]
            sum = sum + last_digit
        isAlternate = not isAlternate
        count_digits = count_digits + 1
        temp_card.pop()

    return sum


# Get credit card number
def get_number():
    number = get_string("Number: ")
    for digit in number:
        credit_card.append(int(digit))


# Main function


def main():
    get_number()
    if sum_every_digit() % 10 != 0:
        print("INVALID")
        return 1
    check()


# Run main()
if __name__ == "__main__":
    main()
