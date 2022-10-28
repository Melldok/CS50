#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //As long as the 3 values are the same, image is gray. Higher value = lighter shade, lower, darker.
    //Go trough each row, and in that row, through each pixel. Calculate average values of RGB and give that value to the Gray.

    for(int i = 0; i < height; i++)
    {

        int gray = 0;

        //Basically what we did here is two loops that will iterate for each row (height) and each pixel (width)
        for(int j = 0; j < width; j++)
        {
            //Creating an integer called gray that will be the result of summing all the RGB and dividing by 3.0, which we will round and give that result to all colors previously calculated.
            gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = gray;

        }
    }
    return;
}

// Convert image to sepia
/*Formula sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
  sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
  sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue */

void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    //same double loop approach
    for(int i = 0; i < height; i++){


        for(int j = 0; j < width; j++)
        {
           //Naming the originals

           int originalRed = image[i][j].rgbtRed;
           int originalGreen = image[i][j].rgbtGreen;
           int originalBlue = image[i][j].rgbtBlue;

           //Applying the formula

           int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
           int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
           int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

           //Setting the 0 - 255 range

           int min = 0;
           int max = 255;

           //Applying

           if(sepiaRed > max)
           {
            sepiaRed = 255;
           }
           if(sepiaRed < min)
           {
            sepiaRed = 0;
           }
           if(sepiaGreen > max)
           {
            sepiaGreen = 255;
           }
           if(sepiaGreen < min)
           {
            sepiaGreen = 0;
           }
           if(sepiaBlue > max)
           {
            sepiaBlue = 255;
           }
           if(sepiaBlue < min)
           {
            sepiaBlue = 0;
           }

           //Setting the generated results

           image[i][j].rgbtRed = sepiaRed;
           image[i][j].rgbtGreen = sepiaGreen;
           image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Each pixel on the row will have its place but reversed. (If pixel input == pixel input rowend - 2, pixel output = rostart + 2)

    for(int i = 0; i < height; i++)
    {
        //This time we want to go half the way of the width, because we want to mirror it. We will be using the swapping technique that is described on the lecture
        for(int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)]; //Determinates the end of the array
            image[i][width - (j + 1)] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
//loop through each pixel and take average value of pixels arround, then apply to current pixel
{
    //creating temporary copy of the image, so we can store the values that we will get
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

     for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int averageRed;
            int averageGreen;
            int averageBlue;

            averageRed =  averageGreen =  averageBlue = 0;
            float counter = 0.00;

            //loop through pixels and calculate sorrounding pixels (only valid)

            for(int x = -1; x < 2; x++) //Range of the position of surrounding pixels ond X line
            {
                for(int y = -1; y < 2; y++) //Range of the position of surrounding pixels ond Y line
                {
                    int surroundingX = i + x;
                    int surroundingY = j + y;

                    //Check if surrounding pixel is valid (Inside of image)

                    if(surroundingX < 0 || surroundingX > (height -1) || surroundingY < 0 || surroundingY > (width -1))
                    {
                        continue; //If pixel is invalid, skip and continue looping
                    }

                    //Get image value

                    averageRed += image[surroundingX][surroundingY].rgbtRed;
                    averageGreen += image[surroundingX][surroundingY].rgbtGreen;
                    averageBlue += image[surroundingX][surroundingY].rgbtBlue;

                    counter ++;

                }

                //Calculate average of surrounding pixels

                temp[i][j].rgbtRed = round(averageRed / counter);
                temp[i][j].rgbtGreen = round(averageGreen / counter);
                temp[i][j].rgbtBlue = round(averageBlue / counter);
            }
        }
    }

    //Update original values with generated ones

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
