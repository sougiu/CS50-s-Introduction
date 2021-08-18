// To run this code, go to: https://sandbox.cs50.io/ to get access of all libraries used.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for the pyramids height
    int h = 0;
    do 
    {
        h = get_int("How tall should your pyramid be? ");
    }
    while (h < 1 || h > 8);
    
    // Print the pyramids
    for (int i = 0; i < h; i++)
    {
        // Print spaces to make the blocks look like a pyramid 
        for (int j = i + 1; j < h; j++)
        {
            printf(" ");
        }
        
        // Print left blocks
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        // Print gap
        for (int j = 0; j < 2; j++)
        {
            printf(" ");
        }
        
        // Print right blocks
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}