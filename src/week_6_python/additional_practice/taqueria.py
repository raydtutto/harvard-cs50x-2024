from cs50 import get_string

# Original menu
original_menu = {
    "Baja Taco": 4.25,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}


def get_total_price(menu):

    total = 0

    # Get the order of items from the user
    while True:
        try:
            # Get input
            item = get_string("Item: ")
            if item is None:
                # print()
                break
            item = item.lower()

            # Calculate total price
            if item in menu:
                total += menu[item]
                print(f"${total:.2f}")

            # Handle invalid input
            if item not in menu:
                print(f"{item.title()} was not found. Try again")
                continue

        # Propmt user until the user inputs Control-D
        except EOFError:
            print()
            break


# Main program


def main():

    # Convert menu titles to lower case
    menu = {key.lower(): value for key, value in original_menu.items()}

    # Get total price
    get_total_price(menu)
    print()


# Run main()
if __name__ == "__main__":
    main()
