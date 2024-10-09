from cs50 import get_int


def print_hash(h):
    for i in range(h):
        print("#", end="")


def print_space(h):
    for i in range(h):
        print(" ", end="")


def main():
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break

    for i in range(height):
        print_space(height - i - 1)
        print_hash(i + 1)
        print()


if __name__ == "__main__":
    main()
