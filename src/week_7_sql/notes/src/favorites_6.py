import csv

from collections import Counter

# Open the file
with open("favorites.csv", "r") as file:
    # Read data and import into reader
    reader = csv.DictReader(file)

    # Create a collection
    counts = Counter()

    for row in reader:
        favorite = row["language"]
        counts[favorite] += 1

for favorite in sorted(counts, key=counts.get, reverse=True):
    print(f"{favorite}: {counts[favorite]}")
