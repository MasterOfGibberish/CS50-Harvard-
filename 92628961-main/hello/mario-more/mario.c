#include <stdio.h>
#include <cs50.h>
void draw(int n);
int main(void)
{
    int n=0;
    while(n<=0 || n>=9)   //ask for a positive and lower than 9 int number.
    {
     n=get_int("Type an int (between 0 and 9): ");
    }

    if(n>0 && n<=8)
    {
        draw(n);
    }
}

void draw(int n)
{
    if(n<=0)
    {
        return;
    }
   draw(n-1);
   for(int i=0;i<n;i++)
   {
       printf("#");
   }
   printf("\n");
}

