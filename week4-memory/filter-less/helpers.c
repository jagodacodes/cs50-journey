#include "helpers.h"
#include <math.h>
#include <stdint.h>

void swap(RGBTRIPLE *x, RGBTRIPLE *d);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i < height; i++)
    {
        for(int j=0; j < width; j++)
            {
                int srednia = round(((image[i][j].rgbtRed) +
                                 (image[i][j].rgbtGreen) +
                                 (image[i][j].rgbtBlue)) / 3.0) ;// wez srednia z BGR
                image[i][j].rgbtRed = srednia;
                image[i][j].rgbtBlue = srednia;
                image[i][j].rgbtGreen = srednia;
            }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for(int k = 0; k < height; k++) // iteracja po wersach (rozpoczynamy nowy wers dopiero jak przeszlismy przez wszystkie kolumny poprzedniego wersu)
        {
            for(int l = 0; l < width; l++) // iteracja od lewej do prawej w danym rzedzie pikseli
                {
                    int originalRed = image[k][l].rgbtRed;
                    int originalBlue = image[k][l].rgbtBlue;
                    int originalGreen = image[k][l].rgbtGreen;
                    int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
                    int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
                    int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
                    if (sepiaRed > 255)
                        {
                            sepiaRed = 255;
                        }
                    if (sepiaGreen > 255)
                        {
                            sepiaGreen = 255;
                        }
                    if (sepiaBlue > 255)
                        {
                            sepiaBlue = 255;
                        }
                    image[k][l].rgbtRed = sepiaRed;
                    image[k][l].rgbtGreen = sepiaGreen;
                    image[k][l].rgbtBlue = sepiaBlue;
                    }
        }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int m = 0; m < height; m++)
        {
            for(int t = 0; t < (width/2); t++)
                {
                    swap(&image[m][t], &image[m][width - t - 1]);

                }
        }
    return;
}

void swap(RGBTRIPLE *x, RGBTRIPLE *d)
    {
        RGBTRIPLE tmp = *x;
        *x = *d;
        *d = tmp;
    }

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
                {
                     copy[i][j] = image[i][j];

                }
        }
        for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    int sumR = 0, sumG = 0, sumB = 0;
                    int count = 0;

                    for (int ni = i - 1; ni <= i + 1; ni++)
                    {
                        for (int nj = j - 1; nj <= j + 1; nj++)
                        {
                            if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                            {
                                sumR += copy[ni][nj].rgbtRed;
                                sumG += copy[ni][nj].rgbtGreen;
                                sumB += copy[ni][nj].rgbtBlue;

                                count++;
                            }
                        }
                    }

                    image[i][j].rgbtRed = round(sumR / (float)count);
                    image[i][j].rgbtGreen = round(sumG / (float)count);
                    image[i][j].rgbtBlue = round(sumB / (float)count);
                }
            }

    return;
}
