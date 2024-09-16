#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
bool cycle_check(int winner, int loser);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    //------------- Test output starts

    // printf("\n");

    // for (int i = 0; i < candidate_count; ++i)
    // {
    //     for (int j = 0; j < candidate_count; ++j)
    //     {
    //         printf("preferences[%i][%i] = %i \n", i, j, preferences[i][j]);
    //     }
    // }
    // printf("\n");

    // for (int i = 0; i < pair_count; ++i)
    // {
    //     printf("%i pair: %i : %i \n", i, pairs[i].winner, pairs[i].loser);
    // }
    // printf("\n");

    // printf("Total %i pairs \n", pair_count);
    // printf("\n");

    // printf("LEGEND True : 1, False : 0 \n");
    // for (int i = 0; i < pair_count; ++i)
    // {
    //     for (int j = 0; j < pair_count; ++j)
    //     {
    //         printf("%i pair. Locked is %i \n", i, locked[i][j]);
    //     }
    // }
    // printf("\n");

    //------------- Test output ends

    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; ++i)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; ++i)
    {
        for (int j = 0; j < candidate_count; ++j)
        {
            if (i < j)
            {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    pair_count = 0;

    for (int i = 0; i < candidate_count; ++i)
    {
        for (int j = 0; j < candidate_count; ++j)
        {
            if (i != j && preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    bool swaped = false;

    for (int i = 0; i < pair_count - 1; ++i)
    {
        int left = preferences[pairs[i].winner][pairs[i].loser];
        int right = preferences[pairs[i + 1].winner][pairs[i + 1].loser];
        if (left < right)
        {
            pair temp = pairs[i];
            pairs[i] = pairs[i + 1];
            pairs[i + 1] = temp;

            swaped = true;
        }
    }

    if (swaped == true)
    {
        sort_pairs();
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; ++i)
    {
        if (!cycle_check(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    return;
}

bool cycle_check(int winner, int loser)
{
    if (loser == winner)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; ++i)
    {
        if (locked[loser][i] == true)
        {
            if (cycle_check(winner, i))
            {
                return true;
            }
        }
    }

    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO

    for (int i = 0; i < candidate_count; ++i)
    {
        bool source = true;

        for (int j = 0; j < candidate_count; ++j)
        {
            if (locked[j][i] == true)
            {
                source = false;
                break;
            }
        }

        if (source == true)
        {
            printf("%s\n", candidates[i]);
        }
    }

    return;
}