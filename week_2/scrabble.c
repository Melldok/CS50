#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    //Keep track of the score
    int score = 0;

    //We use strlen to see the lenght of a string, so we make a loop what will iterate on each letter of the string
    for (int i = 0, len = strlen(word); i < len; i++)
        //This loop has to be case insensitive, so we must make two options to iterate, one with uppercases and one with lowercases
    {
        if (isupper(word[i]))
        {
            //The value of score will be determined by the mathematic process of suming the iteration of the loop minus 65. So it will give us the position of the letter in the table, we will use that position to compare it with the Array position of POINTS[n], which will give us it's points.
            score += POINTS[word[i] - 'A']; //in this case we are able to use capital A as 65, given ASCII table.
        }
        else if (islower(word[i])) //lower case a is 97
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}



   
