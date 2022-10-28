#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    //Check if user uses 1 command argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //Open the file (which will be introduced on argv[1])
    FILE *input_file = fopen(argv[1], "r");

    //check if valid
    //If the adress of the file doesnt exist, it will return NULL and we will print the error
    if(input_file == NULL)
    {
        printf("could not open file");
        return 2;
    }
    //Store 512 bytes blocks into an array
    unsigned char buffer[512];

    //Track number of images generated
    int count_image = 0;

    //File pointer for recover images
    FILE *output_file = NULL;

    //char filename[8]
    char *filename = malloc(8 * sizeof(char));

    //read blocks

    while(fread(buffer, sizeof(char), 512, input_file))
    {

        //check if indicates start of JPEG

        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)

        {
            if (count_image > 0)
            {
                fclose(output_file);
            }
            //write JPEG filenames
            sprintf(filename, "%03i.jpg", count_image);

            //Open output_file
            output_file = fopen(filename, "w");

            //Count images found
            count_image++;
        }


        //check if output is used fot valid input
        if(output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}