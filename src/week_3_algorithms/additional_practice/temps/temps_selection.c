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

    // Selection sort

    // Repeat until no unsorted elements remain:
    // • Search the unsorted part of the data to find the biggest value
    // • Swap the biggest found value with the first element of the unsorted part

    for (int i = 0; i < NUM_CITIES - 1; ++i)
    {
        int max_index = i;
        for (int j = i + 1; j < NUM_CITIES; ++j)
        {
            if (temps[j].temp > temps[max_index].temp)
            {
                // printf("\n\nBefore swap: min_index ~ %i = j ~ %i", max_index, j);
                max_index = j;
                // printf("\nAfter swap: min_index ~ %i = j ~ %i", max_index, j);
            }
        }
        if (max_index != i)
        {
            avg_temp biggest = temps[i];
            // printf("\n\nsmallest = temps[%i] ~ %s, %i", i, temps[i].city,temps[i].temp);

            temps[i] = temps[max_index];
            // printf("\ntemps[%i] = temps[%i] ~ %s, %i", i, max_index, temps[max_index].city,temps[max_index].temp);

            temps[max_index] = biggest;
            // printf("\ntemps[%i] = smallest ~ %s, %i\n", max_index, temps[max_index].city,temps[max_index].temp);
        }
    }
}
