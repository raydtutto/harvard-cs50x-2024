import random
import sys
from cs50 import get_string
from pyfiglet import Figlet


# Initialize font to the default value
f = None


# Check arguments
def argument_input():
    global f

    # Figlet object
    figlet = Figlet()

    # Get the list of fonts
    fonts_list = figlet.getFonts()

    # If no arguments
    if len(sys.argv) == 1:

        # Generate random font
        random_font = random.choice(fonts_list)

        # Assign random font
        f = Figlet(font=random_font)

    # Check font argument
    elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):

        # Get the font from an argument, then convert ot lower-case
        specific_font = sys.argv[2].lower()

        # Search for the font
        if specific_font in fonts_list:

            # Assign specific font
            f = Figlet(font=specific_font)

        # Not found
        else:
            print(f"{specific_font} was not found")
            sys.exit(2)

    # No command
    else:
        print("Invalid input")
        sys.exit(1)


# Main program


def main():
    global f

    # Check arguments
    argument_input()

    # Prompt for text
    text = get_string("Input: ")

    # Print prompted text
    print(f.renderText(f"{text}"))


# Run main()
if __name__ == "__main__":
    main()
