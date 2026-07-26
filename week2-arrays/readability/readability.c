#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
string text = get_string("text:\n");

int letters = 0;
int words = 1;
int sentences = 0;

for(int x = 0; x < strlen(text); x++)
{

        if(isalpha(text[x]))
        {
                letters++;
        }
        else if(text[x] == ' ')
        {
                words++;
        }
        else if(text[x] == '.' || text[x] == '?'  || text[x] == '!' )
        {
                sentences++;
        }
}

float S = (float) sentences / (float) words * 100;
float L = (float) letters / (float) words * 100;

int index = round(0.0588 * L - 0.296 * S - 15.8);

        if (index < 1)
        {
                printf("Before Grade 1\n");
        }
        else if (index > 16)
        {
                printf("Grade 16+\n");
        }
        else
        {
                printf("Grade %i\n", index);
        }
}
