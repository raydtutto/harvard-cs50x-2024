import sys
from cs50 import get_string


# Main function


def main():
    # Prompt for greeting
    greeting = get_string("Greeting: ")

    # Convert to lower-case
    greeting = greeting.lower()

    # Remove whitespaces, then look for 'hello'
    if greeting.strip().startswith("hello"):
        print("$0")
    # Remove whitespaces, then look for 'h'
    elif greeting.strip().startswith("h"):
        print("$20")
    else:
        print("$100")


# Run main()
if __name__ == "__main__":
    main()
