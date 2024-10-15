import csv

# Open the file
with open("favorites.csv", "r") as file:
    # Read data and import into reader
    reader = csv.DictReader(file)

    # Votes counters
    scratch, c, python = 0, 0 ,0

    for row in reader:
        favorite = row['language']
        if favorite == 'C':
            c += 1
        elif favorite == 'Python':
            python += 1
        elif favorite == 'Scratch':
            scratch += 1

# Printing is outside the loop, because at this step
# we don't need an opened file anymore.
print(f"C: {c}")
print(f"Python: {python}")
print(f"Scratch: {scratch}")