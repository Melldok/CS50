#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//Declaring the name and type of the function, we will need an integer for the grade, so we specify an int, which will come as a result of the function.



int main(void)
{
    string text = get_string("Text: ");
    //printf("The introduced text is a grade: \n");

//Declaring all the variables we will need
    int letters = 0;
    int words = 1;
    int sentences = 0;



//A loop to check the conditions

    for(int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i])) //isalpha will check if the character is a letter, and if it is, it will sum 1 to letters
        {
            letters++;
        }
        else if (isspace(text[i])) //isspace will chek if the character is a space, if it is, it will add one point to words, cause each word is separated by a space, but we will need to add one extra point to words at the end, cause the last word doesnt come with a space.
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!') //I used ispunct at the beginning to add points if it's a punctuation mark, but given the problem, it shouuld only add points if one of these three options are met.
        {
            sentences++;
        }
    }
        //Checks for the letters, words and sentences

        /*printf("%i Letters\n", letters);
        printf("%i Words\n", words);
        printf("%i Sentences\n", sentences); */

        //Given the formula on the exercise, we calculate L and S and apply

        float L = (float) letters / (float) words * 100;
        float S = (float) sentences / (float) words * 100;

        //Data not working without adding the (float) mark, so we add it, so the pc treats the data as a floaat.

        int index = round(0.0588 * L - 0.296 * S - 15.8);

        if(index < 1)
        {
            printf("Before Grade 1\n");
        }
        else if(index > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", index);
        }



}






