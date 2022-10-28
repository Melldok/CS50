#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
//This function takes 3 arguments. Voter represent which number is currently voting. Rank represents which rank the voter is currently trying to indicate a preference for. Rank 0 first preference.. rank 1 second.. Name indicates which candidate they are trying to vote for.

/*Look for candidate called name
    If found, update preferences so that they are the voters rank preference, return true.

    Else: Dont update any preferences and return false.

    Recall that preferences[i][j] stores the index of the candidate who is the jth ranked preference for the ith voter.
    */
{
    for (int i = 0; i < candidate_count; i++)
    {
        //If string name matches candidates[i] name
        if (strcmp(name, candidates[i].name) == 0)
        {
            //Update preferences where ith voter has jth ranked preferences.
            preferences[voter][rank] = i;
            //Preferences[voter 1] = [Rank of i]
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    /* Go through each voter, check preferences.
        Vote -> if eliminated == false -> Update votes */
    // TODO


    for (int i = 0; i < voter_count; i++)
        //First loop iterates through each voter
    {
        for (int j = 0; j < candidate_count; j++)
            //Second loop iterates through each candidate the voter voted.
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++ ;
                break;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO


    //if any candidate has more than half of the vote, print out their name and return true
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= (voter_count / 2) + 1)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    //If nobody won the election yet, return false.

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    //Declaring a starting point, which will go down through the loop
    int min = voter_count;
    // TODO
    //If the candidate is not eliminated and its total vote count is lower than the minimum, minimum will be that number. Opposite of what we did in plurality.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    //We need to track 1.-- The number of candidate still remaining in the election, and 2.-- The number of candidates that has the less number of votes
    //Creating the variables
    int remaining = 0;
    int min_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
            //If candidate not eliminated, remaining++
        {
            remaining++;
            if (candidates[i].votes == min)
            {
                min_votes++;
            }
        }
    }
    //if number of remaining candidates is same as minimum votes, return true.
    if (remaining == min_votes)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }

    }
    return;
}