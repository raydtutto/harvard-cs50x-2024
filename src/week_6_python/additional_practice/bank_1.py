import sys
from cs50 import get_string


# Main function


def main():
    # Prompt for greeting
    greeting = get_string("Greeting: ")

    # Convert to lower-case
    greeting = greeting.lower()

    # 'hello' presence
    hello = False

    # First letter presence
    first = False
    first_letter = 0

    # other greeting
    other = False

    # count of 'h'
    count = 0

    # Address of 'h'
    address = 0

    # Iterate through each character in greeting
    for i in range(len(greeting)):
        # Look for the first letter
        if greeting[i].isalpha():
            if first:
                break
            first_letter = i
            first = True
        # Look for 'hello'
        if greeting[i:i+5] == 'hello':
            hello = True
            break
        # Look for 'h'
        if greeting[i] == 'h':
            # If 'h' was already found
            if count > 1:
                break
            # Count 'h'
            count += 1
            address = i

    # If 'hello' was found
    if hello:
        print("$0")
        # Terminate program
        sys.exit(0)
    elif count == 1 and address == first_letter:
        print("$20")
        # Terminate program
        sys.exit(0)
    # If other greeting
    else:
        print("$100")


# Run main()
if __name__ == "__main__":
    main()
