#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    long number = get_long("type your credit card number: ");
    int g = 0;
    long cc = number;
    while (cc > 0)
    {
        cc = cc / 10;
        g++;
    }
    if (g < 13 || g > 16)
    {
        printf("INVALID\n");
        return 0;
    }
    int sum, sum1, sum2, index, index2, index3;
    int skaidymas = 10;
    long skaidymas2 = 1;
    for(int i = g; i > 0; i--)
    {
        index=number/skaidymas2%skaidymas;
        skaidymas2=skaidymas2*10;
        if(g % 2 == 0)
        {
            if(i % 2 == 0)
            {
                sum1=sum1+index;
            }
            else
            {
                if(index*2 > 9)
                {
                    index=index*2;
                    index2=index%10;
                    index3=index/10%10;
                    index=index2+index3;
                    sum2=sum2+index;
                }
                else
                {
                sum2=sum2+index*2;
                }
            }
        }
        else
        {
            if(i % 2 == 0)
            {
                if(index*2 > 9)
                {
                    index=index*2;
                    index2=index%10;
                    index3=index/10%10;
                    index=index2+index3;
                    sum2=sum2+index;
                }
                else
                {
                sum2=sum2+index*2;
                }
            }
            else
            {
                sum1=sum1+index;
            }
        }
    }
    sum=sum1+sum2;
     if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long n = number;
    do
    {
        n = n / 10;
    }
    while (n > 100);
    int n1=n%10;
    int n2=n/10%10;
    if (g >= 13 && g <= 16 && index == 4)
    {
        printf("VISA\n");
        return 0;
    }
    else if (g == 15 && n2 == 3 && (n1==4 || n1==7))
    {
        printf("AMEX\n");
        return 0;
    }
    else if (g==16 &&  n2 == 5 && (0 < n1 && n1 < 6))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}