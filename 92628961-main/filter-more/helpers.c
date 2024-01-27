#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = temp[i][j];
            }
        }
        else
        {
            for (int j = 0; j < (width - 1)  / 2; j++)
            {
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = temp[i][j];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Blue = 0;
            float Green = 0;
            float Red = 0;
            float counter = 0;

            for (int h = -1; h < 2; h++)
            {
                for (int g = -1; g < 2; g++)
                {
                    if (i + h < 0 || i + h > height - 1)
                    {
                        continue;
                    }

                    if (j + g < 0 || j + g > width - 1)
                    {
                        continue;
                    }

                    Blue += image[i + h][j + g].rgbtBlue;
                    Green += image[i + h][j + g].rgbtGreen;
                    Red += image[i + h][j + g].rgbtRed;
                    pixels++;
                }
            }

            temp[i][j].rgbtBlue = round(Blue / pixels);
            temp[i][j].rgbtGreen = round(Green / pixels);
            temp[i][j].rgbtRed = round(Red / pixels );
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
