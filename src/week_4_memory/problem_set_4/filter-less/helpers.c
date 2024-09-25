#include "helpers.h"
#include <math.h>

// Find average
void avgColor(int x, int y, int height, int width, RGBTRIPLE image[height][width], BYTE *r, BYTE *g,
              BYTE *b);

// Check color range between 0 to 255
void check_range(float *color);

// Position array for blur()
typedef struct
{
    int x;
    int y;
} __attribute__((__packed__)) BOX;

// Check color range between 0 to 255
void check_range(float *color)
{
    if (*color > 255.0)
    {
        *color = 255.0;
    }

    return;
}

// Find average for blur()
void avgColor(int x, int y, int height, int width, RGBTRIPLE image[height][width], BYTE *r, BYTE *g,
              BYTE *b)
{
    float avgBlue = 0, avgGreen = 0, avgRed = 0;
    int counter = 0, search_pos_size = 9;

    // Declare position
    BOX search_pos[] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0},
                        {1, 0},   {-1, 1}, {0, 1},  {1, 1}};

    // Get sum
    for (int i = 0; i < search_pos_size; i++)
    {
        int search_x = search_pos[i].x + x;
        int search_y = search_pos[i].y + y;

        if (search_x < 0 || search_x >= height || search_y < 0 || search_y >= width)
        {
            continue;
        }

        avgBlue += image[search_x][search_y].rgbtBlue;
        avgGreen += image[search_x][search_y].rgbtGreen;
        avgRed += image[search_x][search_y].rgbtRed;
        counter++;
    }

    // Get average
    avgBlue /= counter;
    avgGreen /= counter;
    avgRed /= counter;

    // Check color range between 0 to 255
    check_range(&avgBlue);
    check_range(&avgGreen);
    check_range(&avgRed);

    // Result
    *r = round(avgRed);
    *g = round(avgGreen);
    *b = round(avgBlue);

    return;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            // Find average
            float avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;

            // Round double
            BYTE result = (BYTE) round(avg);

            // Result
            image[i][j].rgbtBlue = result;
            image[i][j].rgbtGreen = result;
            image[i][j].rgbtRed = result;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            // Sepia formula
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                              .131 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                               .168 * image[i][j].rgbtBlue;
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                             .189 * image[i][j].rgbtBlue;

            // Check color range between 0 to 255
            check_range(&sepiaBlue);
            check_range(&sepiaGreen);
            check_range(&sepiaRed);

            // Result
            image[i][j].rgbtBlue = (BYTE) round(sepiaBlue);
            image[i][j].rgbtGreen = (BYTE) round(sepiaGreen);
            image[i][j].rgbtRed = (BYTE) round(sepiaRed);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width / 2; ++j)
        {
            // Swap
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of an image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Blur copy
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            BYTE r = 0, g = 0, b = 0;
            avgColor(i, j, height, width, image, &r, &g, &b);
            copy[i][j].rgbtBlue = b;
            copy[i][j].rgbtGreen = g;
            copy[i][j].rgbtRed = r;
        }
    }

    // Get an image
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}