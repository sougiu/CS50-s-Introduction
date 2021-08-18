// To run this code, go to: https://sandbox.cs50.io/ to get access of all libraries used.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Prompt the user for text
    string text = get_string("Text: ");
    
    // Compute data from text
    int letters = 0;
    int words = 1;
    int sentences = 0;
    
    for (int i = 0, lenght = strlen(text); i < lenght; i++)
    {
        // Compute how many letters
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        // Compute how many words
        else if (text[i] == ' ')
        {
            words++;
        }
        // Compute how many sentences
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }


    // Average number of letters per 100 words
    float L = letters * 100.0 / words;
    
    // Average number of sentences per 100 words
    float S = sentences * 100.0 / words;
    
    // Apply the Coleman-Liau index
    double index = 0.0588 * L - 0.296 * S - 15.8;
    
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index >= 1)
    {
        printf("Grade %i\n", (int) round(index));
        
    }
    else 
    {
        printf("Before Grade 1\n");
    }
    
}