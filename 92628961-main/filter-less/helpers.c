#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) //every pixels change to average of its color sum
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) //count by formula
        {
            sepiaRed = round(0.393 * image[i][j].rgbtRed + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtBlue * 0.189);
            sepiaGreen = round(0.349 * image[i][j].rgbtRed + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtBlue * 0.168);
            sepiaBlue = round(0.272 * image[i][j].rgbtRed + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtBlue * 0.131);

            if (sepiaRed > 255) //color range is between 0 and 255 so everything higher you must equal to max
            {
                image[i][j].rgbtRed = 255;
            }
            if (sepiaRed <= 255)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            if (sepiaGreen <= 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            if (sepiaBlue <= 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
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
        if (width % 2 == 0) //if width is odd, swap pixels
        {
            for (int j = 0; j < width / 2; j++)
            {
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = temp[i][j];
            }
        }
        if (width % 2 != 0) //if width is not odd, swap pixels -1 time less
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
    int SBlue, SRed, SGreen;
    for (int i = 0; i < height; i++) //checking every pixel
    {
        for (int j = 0; j < width; j++)
        {
            float Blue = 0;
            float Green = 0;
            float Red = 0;
            int pixels = 0;
            for (int h = -1; h < 2; h++)  //checking every neighboor pixel
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
                    Blue += image[i + h][j + g].rgbtBlue;  //counting neighbooring pixels
                    Green += image[i + h][j + g].rgbtGreen;
                    Red += image[i + h][j + g].rgbtRed;
                    pixels++;
                }
            }
            SBlue = round(Blue / pixels); //counting new pixel color
            SGreen = round(Green / pixels);
            ed = round(Red / pixels);
            temp[i][j].rgbtBlue = SBlue;
            temp[i][j].rgbtGreen = SGreen;
            temp[i][j].rgbtRed = SRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;  //equaling original picture to new
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
