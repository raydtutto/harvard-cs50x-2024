from cs50 import get_int

# If there is a valid input break from the infinite loop
while True:
    n = get_int("Height: ")
    if n > 0:
        break

for i in range(n):
    print("#")
