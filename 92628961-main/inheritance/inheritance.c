#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // Allocate memory for new person
    person *p = malloc(sizeof(person));

    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // Set parent pointers for current person
        p->parents[0] = parent0;
        p->parents[1] = parent1;

        // Randomly assign current person's alleles based on the alleles of their parents
        p->alleles[0] = parent0->alleles[rand() % 2];
        p->alleles[1] = parent1->alleles[rand() % 2];
    }

    // If there are no generations left to create
    else
    {
        // Set parent pointers to NULL
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        // Randomly assign alleles
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    // Return newly created person
    return p;
}

// Print a person's information and recursively print their parents' information
void print_family(person *p, int generation)
{
    // Print indentation for current generation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person's alleles
    printf("%c%c\n", p->alleles[0], p->alleles[1]);

    // Recursively print parents' information
    if (p->parents[0] != NULL)
    {
        print_family(p->parents[0], generation + 1);
        print_family(p->parents[1], generation + 1);
    }
}

// Free memory for a person and all of their ancestors
void free_family(person *p)
{
    // Base case: person is NULL
    if (p == NULL)
    {
        return;
    }

    // Recursively free both of the person's parents
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Free the person
    free(p);
}

// Randomly generate a blood type allele
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
