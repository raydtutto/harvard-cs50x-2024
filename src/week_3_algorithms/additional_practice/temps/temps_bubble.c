// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // Add your code here

    // Bubble Sort

    // Set swap counter to a non-zero value
    // • Repeat until the swap counter is 0:
    //     • Reset swap counter to 0
    //     • Look at each adjacent pair
    //         • If two adjacent elements are not in order, swap them and add one to the swap counter

    bool swapped = false;

    for (int i = 0; i < NUM_CITIES - 1; ++i)
    {
        for (int j = 0; j < NUM_CITIES - 1; ++j)
        {
            if (temps[j].temp < temps[j + 1].temp)
            {
                avg_temp temporary = temps[j];
                // printf("\n\ntemporary =  temps[%i] ~ %s, %i\n", j, temps[j].city, temps[j].temp);

                temps[j] = temps[j + 1];
                // printf("\ntemps[%i] = temps[%i] ~ %s, %i\n", j, j + 1, temps[j + 1].city, temps[j + 1].temp);

                temps[j + 1] = temporary;
                // printf("\ntemps[%i] = temporary ~ %s, %i\n\n", j + 1, temporary.city, temporary.temp);

                swapped = true;
            }
        }
    }

    if (swapped == false)
    {
        return;
    }
}