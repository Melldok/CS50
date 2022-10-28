// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file


        //Read the header from the input file
        uint8_t header[HEADER_SIZE]; //Defining the data tuype of the header. As commented on the instructions. It stores an 8-bit unsigned integer. Header size is 44 bytes.
        fread(header, HEADER_SIZE, 1, input);
        //Write the header to the output file
        fwrite(header, HEADER_SIZE, 1, output);



    // TODO: Read samples from input file and write updated data to output file
        int16_t buffer; //As said on the instructions, this is the data type for each of the samples. It stores 16-bit signed integer. (Because each sample is 2 bytes)
        /*
            Repeat for each sample:
                Read the sample from the input file
                Multipy the sample value by the volume factor
                Write the new sample to the output file
        */
       while (fread(&buffer, sizeof(int16_t), 1, input))
       //A loop that will iterate through all samples until it reaches the end of the file, once is not able to read anymore data, it will return 0 and it will close.
       {
        //update volume
            buffer = buffer * factor;
            fwrite(&buffer, sizeof(int16_t), 1, output);
       }


    // Close files
    fclose(input);
    fclose(output);
}
