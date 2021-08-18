// To run this code, go to: https://sandbox.cs50.io/ to get access of all libraries used.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User's start population
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    
    // User's final population
    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while (end < start);
    
    // Number of years to reach final populatiom
    int years = 0;
    while (end > start)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    
    // Output of how many years to reach final population
    printf("Years: %i\n", years);
}