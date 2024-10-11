import re
from cs50 import get_string


# Declare text
text = ''


# Count letters
def count_letters():
    global text
    sum = 0
    # Iterate through text
    for char in text:
        # Check for letters
        if re.match("[a-zA-Z]", char):
            sum += 1
    return sum


# Count words
def count_words():
    global text
    sum = 0
    # Iterate through text
    for char in text:
        # Check for spaces
        if char == ' ':
            sum += 1
    # Sum plus the last word
    return sum + 1


# Count sentences
def count_sentences():
    global text
    sum = 0
    count = 0
    ellipsis_track = False
    # Iterate through text
    for char in text:
        # Check for ! and ?
        if char == '!' or char == '?':
            sum += 1
        # Check for dots
        if char == '.':
            count += 1
            # Check for ellipsis
            if ellipsis_track and count == 3:
                sum += 1
                ellipsis_track = True
            # Check for regular dot
            elif count == 1:
                sum += 1
        # Reset to find a new ellipsis
        else:
            count = 0
            ellipsis_track = False

    return sum


# Grade text
def grade(avg1, avg2):
    # Coleman-Liau formula
    index = (0.0588 * avg1) - (0.296 * avg2) - 15.8
    # Grading
    if index < 1.0:
        print("Before Grade 1")
    elif index >= 16.0:
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")


# Main function


def main():
    global text
    # Prompt for a text
    text = get_string("Text: ")

    # Count letters, words and sentences from the text
    letters = count_letters()
    words = count_words()
    sentences = count_sentences()

    # Calculate average of letters and sentences
    avg_letters = letters / words * 100
    avg_sentences = sentences / words * 100

    # Grade text
    grade(avg_letters, avg_sentences)


# Run main()
if __name__ == "__main__":
    main()
