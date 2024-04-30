/* Program prints as output “Grade X” where “X” is the grade level computed,
 * rounded to the nearest integer. If the grade level is 16 or higher (equivalent to
 * or greater than a senior undergraduate reading level), program outputs
 * “Grade 16+” instead of giving the exact grade number. If the grade level is less than 1,
 * program outputs “Before Grade 1”. */

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototype
int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
void grade(double avg1, double avg2);

int main(int argc, char *argv[])
{
    string text = get_string("Text: ");

    // Calculating the amount of letters, words and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculating the average of letters and sentences
    double avg_letters = (double) letters / (double) words * 100;
    double avg_sentences = (double) sentences / (double) words * 100;

    // Calling a function to declare the grade
    grade(avg_letters, avg_sentences);

    return 0;
}

// Get the number of letters
int count_letters(string s)
{
    int sum = 0;

    for (int i = 0, length = strlen(s); i < length; ++i)
    {
        // Check letters
        if (isupper(s[i]) || islower(s[i]))
        {
            sum++;
        }
    }

    return sum;
}

// Get the number of words
int count_words(string s)
{
    int sum = 0;

    for (int i = 0, length = strlen(s); i < length; ++i)
    {
        // Check words
        if (isspace(s[i]))
        {
            sum++;
        }
    }

    return sum + 1;
}

// Get the number of sentences
int count_sentences(string s)
{
    int sum = 0, count = 0;
    bool ellipsis_track = false;

    for (int i = 0, length = strlen(s); i < length; ++i)
    {
        int temp = (int) s[i];

        // Check for ! and ?
        if (temp == 33 || temp == 63)
        {
            sum++;
        }
        // Check for . and ...
        if (temp == 46)
        {
            count++;
            if (ellipsis_track && count == 3)
            {
                sum++;
                ellipsis_track = true;
            }
            else if (count == 1)
            {
                sum++;
            }
        }
        else
        {
            count = 0;
            ellipsis_track = false;
        }
    }

    return sum;
}

// Checks the grade
void grade(double avg1, double avg2)
{
    double index = (0.0588 * avg1) - (0.296 * avg2) - 15.8;

    if (index < 1.0f)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16.0f)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}