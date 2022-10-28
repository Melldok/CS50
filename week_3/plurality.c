#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO

    //Iterate through array

    //First though was to iterate through the array of candidates itself, an int cant be compared to a pointer, so best approach is to itera through candidate_count, which is an integer also.
    for (int i = 0; i < candidate_count; i++)
    {
        //We are using i as the number of times the loop will iterate, but also to set the position in the array of candidates[], so each time we iterate, candidates[i] will ++.
        if (strcmp(name, candidates[i].name) == 0)
        {
            //If name matches candidates[i], add one vote to that candidate.
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //Defining a variable that will hold the biggest amount of votes someone got
    int votes = 0;
    // TODO
    //Same aproach of iteration as before
    for (int i = 0; i < candidate_count; i ++)
    {
        //The loop will iterate through the array, each time it finds a bigger number (of votes) than votes, it will update votes. (We are working local and global scoping here.)
        if (candidates[i].votes > votes)
        {
            votes = candidates[i].votes;
        }
    }

    //Checking which candidate has the maximum votes and printing its name.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == votes)
        {
            printf("%s\n", candidates[i].name);
        }

    }



    return;
}