#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    //asking the question at least once
    do
    {
        height = get_int("Specify the pyramid's height: ");
//adding a simple error to guide the user, it will only appear if the user writes the wrong number.
        if (height <= 0 || height > 8)
        {
            printf("You must specify a number between 1 and 8\n");
        }
        ; //Setting a while loop that'll check if the user writes the correct number. If so, the loop will stop and the result will be printed.
    }
    while (height <= 0 || height > 8);
    {
        //when the condition is reached, the next loop will start
        //For each row
        for (int i = 0; i < height; i++)
        {
            //inverted nested loop that will print spaces depending of rows and height
            for (int x = height - 1; x > i; x--)
            {
                printf(" ");
            }
            //nested loop to change rows and print hashes
            for (int j = 0; j <= i; j++)
            {
                //print a brick
                printf("#");


            }
            //move to next row
            printf("\n");
        }

    }


}