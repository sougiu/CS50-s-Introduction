// To run this code, go to: https://sandbox.cs50.io/ to get access of all libraries used.

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Prototype
bool validate(int elements, string arguments[]);
string cipher(string valid_key, string text);

int main(int elements, string arguments[])
{
    // Validate the input key
    if (elements == 1 || validate(elements, arguments) == false)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    // Replace user's text with its ciphered equivalent
    else
    {
        string plain_text = get_string("plaintext: ");
        printf("ciphertext: %s\n", cipher(arguments[1], plain_text));
    }
}

bool validate(int elements, string arguments[])
{
    int lenght = strlen(arguments[1]);
    
    if (elements == 1 || elements > 2 || lenght != 26)
    {
        return false;
    }
    else
    {
        // Standardizes all letters to upper case
        int key[lenght];
        for (int i = 0; i < lenght; i++)
        {
            key[i] = toupper(arguments[1][i]);
        }
            
        // Validate if all elements are alphabetical and unique
        int alpha = 0;
        int repeated = 0;
            
        for (int i = 0; i < lenght; i++)
        {
            if (key[i] >= 'A' && key[i] <= 'Z')
            {
                alpha++;
                    
                for (int r = 0; r < lenght; r++)
                {
                    if (key[i] == key[r])
                    {
                        repeated++;
                    }
                }
            }
        }
            
        if (alpha == 26 && repeated == 26)
        {
            return true;
        }
        return false;
    }
}


string cipher(string valid_key, string text)
{
    // User's valid key lenght and tex
    int key_lenght = strlen(valid_key);
    int text_lenght = strlen(text);
    
    // Standardizes all letters to upper or lower case
    int upper_key[key_lenght];
    int lower_key[key_lenght];
            
    for (int i = 0; i < key_lenght; i++)
    {
        upper_key[i] = toupper(valid_key[i]);
        lower_key[i] = tolower(valid_key[i]);
    }
                
    // Replaces user's text with its ciphered equivalent
    for (int i = 0; i < text_lenght; i++)
    {
        // Output is case sensitive
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = upper_key[text[i] - 'A'];
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = lower_key[text[i] - 'a'];
        }
                    
        // All non alphabethic caracters are kept unchanged
        else
        {
            text[i] = text[i];
        }
    }
    return text;
}