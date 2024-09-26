#include "helpers.h"
#include <math.h>

typedef struct
{
    float x;
    float y;
} __attribute__((__packed__)) KERNEL;

// Check range < 255
void check_range_float(float *color)
{
    if (*color > 255)
    {
        *color = 255;
    }
    else if (*color < 0)
    {
        *color = 0;
    }
}

void check_range_byte(BYTE *color)
{
    if (*color > 255)
    {
        *color = 255;
    }
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average
            float avg =
                (float) (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0f;

            // Round float
            BYTE result = (BYTE) round(avg);

            // Check range < 255
            check_range_byte(&result);

            // Result
            image[i][j].rgbtBlue = result;
            image[i][j].rgbtGreen = result;
            image[i][j].rgbtRed = result;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
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
    // Copy image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Blur image
    // Loop through image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float r = 0, g = 0, b = 0, counter = 0;

            // Loop through box around pixel
            for (int x = -1; x < 2; x++)
            {
                if (x + i < 0 || x + i >= height)
                {
                    continue;
                }
                for (int y = -1; y < 2; y++)
                {
                    if (y + j < 0 || y + j >= width)
                    {
                        continue;
                    }

                    b += image[x + i][y + j].rgbtBlue;
                    g += image[x + i][y + j].rgbtGreen;
                    r += image[x + i][y + j].rgbtRed;
                    counter++;
                }
            }
            // Get average
            b /= counter;
            g /= counter;
            r /= counter;

            // Check color range between 0 to 255
            check_range_float(&b);
            check_range_float(&g);
            check_range_float(&r);

            copy[i][j].rgbtBlue = (BYTE) round(b);
            copy[i][j].rgbtGreen = (BYTE) round(g);
            copy[i][j].rgbtRed = (BYTE) round(r);
        }
    }

    // Get an image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Edge image

    // Gx = {-1, -2, -1
    //        0,  0,  0
    //        1,  2,  1}

    // Gy = {-1, 0, 1
    //       -2, 0, 2
    //       -1, 0, 1}

    // KERNEL name[] = {x, y}
    KERNEL G[] = {{-1, -1}, {-2, 0}, {-1, 1}, {0, -2}, {0, 0}, {0, 2}, {1, -1}, {2, 0}, {1, 1}};
    KERNEL pos[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    float r, g, b, xR, xG, xB, yR, yG, yB;

    // Loop through image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            r = g = b = 0;
            xR = xG = xB = 0;
            yR = yG = yB = 0;

            // Loop through box around pixel
            for (int k = 0; k < 9; k++)
            {
                int x = pos[k].x + i;
                int y = pos[k].y + j;

                if (x < 0 || x >= height || y < 0 || y >= width)
                {
                    r = g = b = 0;
                    continue;
                }

                // G for r,g,b
                // row1 = (-1(color[i: -1][j: -1])) + 0(color[i: -1][j: 0]) + 1(color[i: -1][j: 1])
                // row2 = (-2(color[i: 0] [j: -1])) + 0(color[i: 0] [j: 0]) + 2(color[i: 0] [j: 1])
                // row3 = (-1(color[i: 1] [j: -1])) + 0(color[i: 1] [j: 0]) + 1(color[i: 1] [j: 1])
                // G = row1 + row2 + row3

                xB += (G[k].x * image[x][y].rgbtBlue);
                xG += (G[k].x * image[x][y].rgbtGreen);
                xR += (G[k].x * image[x][y].rgbtRed);

                yB += (G[k].y * image[x][y].rgbtBlue);
                yG += (G[k].y * image[x][y].rgbtGreen);
                yR += (G[k].y * image[x][y].rgbtRed);
            }

            // color = sqrt(pow(Gx, 2) + pow(Gy, 2))
            b = sqrt(pow(xB, 2) + pow(yB, 2));
            g = sqrt(pow(xG, 2) + pow(yG, 2));
            r = sqrt(pow(xR, 2) + pow(yR, 2));

            // Check color range between 0 to 255
            check_range_float(&b);
            check_range_float(&g);
            check_range_float(&r);

            copy[i][j].rgbtBlue = (BYTE) round(b);
            copy[i][j].rgbtGreen = (BYTE) round(g);
            copy[i][j].rgbtRed = (BYTE) round(r);
        }
    }

    // Get an image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}