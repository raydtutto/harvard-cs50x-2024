class Jar:
    # Initialize a cookie jar with the given capacity
    def __init__(self, capacity=12):

        # Set jar's capacity
        self._capacity = capacity

        # Start from the empty jar
        self._size = 0

        # Avoid negative size value
        if self._capacity < 0:
            raise ValueError("No cookies left T_T")

    # Number of cookies in the cookie jar
    def __str__(self):

        # Get the amount of cookies
        n = self._size

        # Set string to emoji
        str = '🍪'

        # Multiply emoji by the amount of cookies
        return str * n

    # Add cookies
    def deposit(self, n):

        # Calculate the new amount of cookies
        result = self._size + n

        # Check for overload
        if result > self._capacity:
            raise ValueError(f"Can't add {n} cookies. Too much!")
        # No overload
        else:
            self._size = self._size + n

    # Withdraw cookies
    def withdraw(self, n):

        # Calculate the amount of left cookies
        result = self._size - n

        # Check for negative value
        if result < 0:
            raise ValueError(
                f"You can't withdraw {n} cookies. There are only {self._size} cookies in the jar.")

        # The new amount is non-negative
        else:
            self._size = self._size - n

    # Define method as a property
    @property
    # Return the cookie jar’s capacity
    def capacity(self):
        return self._capacity

    # Define method as a property
    @property
    # Return the number of cookies actually in the cookie jar
    def size(self):
        return self._size


# Main program


def main():
    # New instance of Jar
    jar = Jar()

    # Observe jar with cookies
    print(str(jar.capacity))

    # Print the amount of cookies with emoji
    print(str(jar))

    # Deposit two cookies
    jar.deposit(12)
    print(str(jar))

    # Withdraw one cookie
    jar.withdraw(4)
    print(str(jar))


# Run main()
if __name__ == "__main__":
    main()
