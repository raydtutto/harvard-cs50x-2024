from cs50 import get_float


# Main function definition


def main():
    # Prompt for change
    while True:
        change = get_float("Change: ")
        if change > 0:
            break

    # Initialize
    quarters = dimes = nickels = pennies = 0
    change = change * 100
    change = int(change)

    # Check for quarters
    if change >= 25:
        quarters = int(change / 25)
        change = change - quarters * 25

    # Check for dimes
    if 10 <= change < 25:
        dimes = int(change / 10)
        change = change - dimes * 10

    # Check for nickels
    if 5 <= change < 10:
        nickels = int(change / 5)
        change = change - nickels * 5

    # Check for pennies
    if 1 <= change < 5:
        pennies = change

    # Calculate the amount of coins
    print(quarters + dimes + nickels + pennies)


# Run main()


if __name__ == "__main__":
    main()
