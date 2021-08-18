// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
const int SAMPLE_SIZE = 2;

// Define a byte Header and a 2-byte Sample
typedef uint8_t Head;
typedef int16_t Samp;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);
    
    Head *header = malloc(HEADER_SIZE);
    
    // Copy header from input file to output file
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // Read samples from input file and write updated data to output file
    Samp buffer;

    while (fread(&buffer, SAMPLE_SIZE, 1, input) == 1)
    {
        buffer = buffer * factor;
        fwrite(&buffer, SAMPLE_SIZE, 1, output);
    }
    
    free(header);
    
    // Close files
    fclose(input);
    fclose(output);
}