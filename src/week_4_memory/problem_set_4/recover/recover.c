#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define JPEGSIZE 512

int main(int argc, char *argv[])
{
    // Single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file %s.\n", argv[1]);
        return 2;
    }

    // Buffer for data block
    uint8_t *buffer = malloc(JPEGSIZE);

    // Image counter
    int counter = 0;

    // Image filename
    char filename[8];

    // Initialize image
    FILE *img = NULL;

    // Repeat until the end of a card:
    while (fread(buffer, sizeof(uint8_t), JPEGSIZE, card) == JPEGSIZE)
    {
        // Find JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            // Start the new image if was already found
            if (img != NULL)
            {
                fclose(img);
            }

            // Writing image
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            counter++;
        }

        // If image was found
        if (img != NULL)
        {
            // Keep writing image
            fwrite(buffer, sizeof(uint8_t), JPEGSIZE, img);
        }
    }

    // Close the last image
    if (img != NULL)
    {
        fclose(img);
    }

    // Free memory
    free(buffer);
    fclose(card);
    return 0;
}