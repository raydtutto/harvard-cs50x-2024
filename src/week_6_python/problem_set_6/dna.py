import csv
import sys


# List of persons
rows = []


# Dictionary with maximum streaks
str_count = {}


# Main function


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Invalid input")
        sys.exit(1)

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as file:
        data = csv.DictReader(file)
        for row in data:
            rows.append(row)
        # # print(f"FIELDS: {data.fieldnames}")      # debug
        # # for element in rows:                     # debug
        # print(f"PERSON: {rows}")                   # debug

    # TODO: Read DNA sequence file into a variable
    # Open .txt file
    with open(sys.argv[2]) as file:
        data = file.read()
        sequence = ''
        # Copy text to sequence
        for char in data:
            sequence += char
        # print(f"SEQUENCE: {sequence}")  # debug

        # TODO: Find longest match of each STR in DNA sequence
        for row in rows:
            for key in row:
                if key != 'name':
                    str_count[key] = longest_match(sequence, key)

    # for key in str_count.keys():  # debug
    #     print(f"KEYS: {key}")     # debug

    # print(f"STR counts: {str_count}")   # debug print to check str_count

    # TODO: Check database for matching profiles
    # Iterate through list
    for row in rows:
        # Trace the matching keys
        match = True
        # Iterate through dictionary with persons
        for key in str_count:
            # Compare each person's key with maximum streaks from sequence
            if int(row[key]) != str_count[key]:
                # Terminate loop if no match
                match = False
                break
        # Print the name if match
        if match:
            print(row['name'])
            sys.exit(0)

    # No such person in dictionary
    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
