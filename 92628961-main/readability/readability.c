#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int l=0;
    int s=0;
    int w=1;

    string text = get_string("Text: ");
    int n = strlen(text);
    for(int i = 0; i < n; i++)
    {
       if(text[i] == 33 || text[i] == 46 || text[i] == 63)
       {
         s++;
       }
       if(text[i] == 32)
       {
        w++;
       }
       if (isalpha(text[i]))
       {
        l++;
       }
    }
    float L = 100 * ((float)l / (float)w);
    float S = 100 * ((float)s / (float)w);
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    //L is the average number of letters per 100 words in the text
    //S is the average number of sentences per 100 words in the text.
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