#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    string filename = argv[1];

    // Opens the file
    FILE *f = fopen(filename, "r");

    // Reads the file
    uint8_t buffer[4];
    int blocks_read = fread(buffer, 1, 4, f);

    // Prints buffered data
    for (int i = 0; i < 4; ++i)
    {
        printf("%i\n", buffer[i]);
    }
    printf("Blocks read: %i\n", blocks_read);

    // Closes the file
    fclose(f);

    return 0;
}