#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Declaring global variable with points
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototypes
int calc_score(string word);
void winner_select(int a, int b);

int main(int argc, char *argv[])
{
    // Prompt players for words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calling a function to calculate the score
    int score1 = calc_score(word1);
    int score2 = calc_score(word2);

    // Winner announcement
    winner_select(score1, score2);

    return 0;
}

// Calculate score
int calc_score(string word)
{
    int sum = 0, temp = 0;

    for (int i = 0, length = strlen(word); i < length; ++i)
    {
        // Check uppercase
        if (isupper(word[i]))
        {
            // A = 65 -> 65 - 65 = 0
            temp = word[i] - 65;
            // Assign items from 'POINTS' to int 'temp'
            temp = POINTS[temp];
        }
        // Check lowercase
        if (islower(word[i]))
        {
            // a = 97 -> 97 - 97 = 0
            temp = word[i] - 97;
            temp = POINTS[temp];
        }
        // Check whether a character is punctuation
        if (ispunct(word[i]))
        {
            temp = 0;
        }
        // Check whether a character is whitespace
        if (isspace(word[i]))
        {
            temp = 0;
        }
        sum += temp;
    }

    // printf("The score is %i\n", sum);
    return sum;
}

// Select the winner
void winner_select(int a, int b)
{
    if (a > b)
    {
        printf("Player 1 wins!\n");
    }
    else if (b > a)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}