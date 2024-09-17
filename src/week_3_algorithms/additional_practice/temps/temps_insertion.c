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

    // Insertion sort

    // Start with second element of the array as first element in the array is assumed to be sorted.
    // Compare second element with the first element and check if the second element is smaller then swap them.
    // Move to the third element and compare it with the second element, then the first element and swap as necessary to put it in the correct position among the first three elements.
    // Continue this process, comparing each element with the ones before it and swapping as needed to place it in the correct position among the sorted elements.
    // Repeat until the entire array is sorted.

    for (int i = 1; i < NUM_CITIES - 1; ++i)
    {
        avg_temp biggest = temps[i];
        int j = i - 1;

        while (j >= 0 && temps[j].temp < biggest.temp)
        {
            temps[j + 1] = temps[j];
            j--;
        }
        temps[j + 1] = biggest;
    }
}