#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_year, end_year;
    int years=0;
    // TODO: Prompt for start size
    do
    {
         start_year = get_int("Start population: ");
    }
    while (start_year < 9);

    // TODO: Prompt for end size
    do
    {
        end_year = get_int("End population: ");
    }
    while (end_year < start_year);

    // TODO: Calculate number of years until we reach threshold
    while (start_year < end_year)
    {
        start_year = start_year + ((start_year / 3) - (start_year / 4));
        years++;
    }

    // TODO: Print number of years
    printf("Years: %d\n", years);
}
