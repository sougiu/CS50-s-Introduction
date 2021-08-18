#include <math.h>

#include "helpers.h"

int hex_max(int color);
int get_hgrid(int i, int j);
int get_wgrid(int i, int j);
int get_hradius(int i, int j);
int get_wradius(int i, int j);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // One way to convert a pixel to grayscale, is to set the red,
    // green, and blue to the same value

    // Define variable
    float grayShade;

    // For each pixel, find the RGB average
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            grayShade = round((image [i][j].rgbtRed + image [i][j].rgbtGreen + image [i][j].rgbtBlue) / 3.0);

            image [i][j].rgbtRed = grayShade;
            image [i][j].rgbtGreen = grayShade;
            image [i][j].rgbtBlue = grayShade;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // One way to convert a pixel to sepia, is to multiply the red,
    // green, and blue by the "magical" numbers below

    // Define variables
    float originalRed;
    float originalGreen;
    float originalBlue;

    // For each pixel, find the RGB proper sepia mix
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image [i][j].rgbtRed;
            originalGreen = image [i][j].rgbtGreen;
            originalBlue = image [i][j].rgbtBlue;

            image [i][j].rgbtRed = hex_max(round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue));
            image [i][j].rgbtGreen = hex_max(round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue));
            image [i][j].rgbtBlue = hex_max(round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue));
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // One way to reflect an image, is to swap pixels

    // Define variable
    RGBTRIPLE temp;

    // For each pixel, find its reflected replacement place and exchange them
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            temp = image [i][j];
            image [i][j] = image [i][width - j - 1];
            image [i][width - j - 1] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Place holder for unchanged pixels
    RGBTRIPLE matrix[height][width];
    
    // Create a matrix
    for (int m = 0; m < height; m++)
    {
        for (int t = 0; t < width; t++)
        {
            matrix[m][t] = image[m][t];
        }
    }
    
    // Initialize counter for considered pixels
    float valid_pixels;
    
    int r;
    int c;
    
    float mixRed;
    float mixGreen;
    float mixBlue;

    // Pixel coordinate
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            valid_pixels = 0;
            
            mixRed = 0;
            mixGreen = 0;
            mixBlue = 0;
            
            // Validate every pixel at the 9*9 block
            
            // Define height primary coordinate
            r = y - 1;
            
            for (int r_count = 0; r_count < 3; r_count++)
            {
                // Define width primary coordinate
                c = x - 1;
                
                for (int c_count = 0; c_count < 3; c_count++)
                {
                    if (r >= 0 && r < height && c >= 0 && c < width)
                    {
                        // Average color of neighbourhood
                        mixRed += matrix[r][c].rgbtRed;
                        mixGreen += matrix[r][c].rgbtGreen;
                        mixBlue += matrix[r][c].rgbtBlue;
                        
                        valid_pixels = valid_pixels + 1;
                    }
                    c++;
                }
                r++;
            }
            // Average color of neighbourhood
            image [y][x].rgbtRed = round((mixRed / valid_pixels));
            image [y][x].rgbtGreen = round((mixGreen / valid_pixels));
            image [y][x].rgbtBlue = round((mixBlue / valid_pixels));
        }
    }
    return;
}

// Adjusts hex to 0 - 255
int hex_max(int color)
{
    if (color > 255)
    {
        return 255;
    }
    else if (color < 0)
    {
        return 0;
    }
    else
    {
        return color;
    }
}