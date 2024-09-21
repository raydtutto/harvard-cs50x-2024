#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // `.csv` is a file format of a lightweight spritesheet
    // we need to tell HOW we want to open a file:
    // "r" - for reading
    // "w" - for writing
    // "a" - for pending

    // `fopen()` returns a pointer to a file
    FILE *file = fopen("phonebook.csv", "a"); // we need to add data to a file, so we use "a"

    // Checks is file exist
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // fprintf(printing to `file`, data to write "%s, %s\n", which data)
    fprintf(file, "%s, %s\n", name, number);

    fclose(file); // closes file

    return 0;
}