from cs50 import get_float


# Create a list of coins
coins = [25, 10, 5, 1]


# Main function definition


def main():
    # Prompt for change
    while True:
        change = get_float("Change: ")
        if change > 0:
            break

    # Convert dollars to cents
    change = change * 100
    change = int(change)

    # Initialize total amount of coins
    total_coins = 0

    # Iterate through a list
    for coin in coins:
        coin_count = int(change / coin)
        change -= coin_count * coin
        total_coins += coin_count

    # Calculate the amount of coins
    print(total_coins)


# Run main()


if __name__ == "__main__":
    main()
