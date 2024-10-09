from cs50 import get_int


# Print hashes


def print_hash(h):
    for i in range(h):
        print("#", end="")

# Print spaces


def print_space(h):
    for i in range(h):
        print(" ", end="")

# Main function definition


def main():
    # Prompt for height
    while True:
        height = get_int("Height: ")
        if 0 < height < 9:
            break

    # Print pyramid
    for i in range(height):
        print_space(height - i - 1)
        print_hash(i + 1)
        print("  ", end="")
        print_hash(i + 1)
        print()


# Run main()


if __name__ == "__main__":
    main()
