#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, string argv[])
{
    // One command line checking
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }

    // checking argv[1] for digits

    for (int i = 0; i < strlen(argv[1]); i++)
        //Since argv[1] is a string, we have to be able to go through each character of the string to check if its an intiger, we use strlen for that, and the isdigit method
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Convert argv[1] from a `string` to an `int`

    int k =  atoi(argv[1]);
    //printf("%i\n", k);

    // Prompt user for plaintext
    string text = get_string("Plain text: ");
    printf("ciphertext: ");

    // For each character in the plaintext:

    for (int i = 0; i < strlen(text); i++)
    {
        // Rotate the character if it's a letter
        // Formula Ci = (pi + k) % 26


        {
            //Check if its Uppercase
            if (isupper(text[i]))
            {
                //The next operation will convert to ASCII each caracter, using the remainder 26 we can reset the loop so it can only go to 26, thats why adding 65 again we make sure it never gets out of ascci uppercase.
                printf("%c", (text[i] - 65 + k) % 26 + 65);
            }
            else if (islower(text[i]))
                //Check if its Lowercase
            {
                printf("%c", (text[i] - 97 + k) % 26 + 97);
            }
            else
            {
                printf("%c", text[i]);
            }
        }



    }
    printf("\n");


}