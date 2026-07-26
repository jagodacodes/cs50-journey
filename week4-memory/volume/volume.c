#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

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

    uint8_t header[HEADER_SIZE];
    fread(header, 1, HEADER_SIZE, input); // ladujemy do headera jednobajtowe 44 elementy z fliku input
    fwrite(header, 1, HEADER_SIZE, output);




    // TODO: Read samples from input file and write updated data to output file

    int16_t sample;

    while (fread(&sample, sizeof(int16_t), 1, input)) // ten fread w whilu zwraca nam 1 lub zero, bo przeiteruje po jednym samplu, jesli on jeszcze bedzie, albo po zadnym jesli juz dojdzie do konca

{
    sample = sample * factor;
    fwrite(&sample, sizeof(int16_t), 1, output);
}


    fclose(input);
    fclose(output);
}
