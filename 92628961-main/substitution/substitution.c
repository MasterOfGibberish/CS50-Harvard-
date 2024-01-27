#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

void substitution(string key);

int main(int argc, string argv[])
{
    int n = strlen(argv[1]);
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            for (int i = 0; i < n ; i++)
            {

                if (!isalpha(argv[1][i]))
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }

                for (int j = i + 1 ; j < n ; j++)
                {

                    if (toupper(argv[1][j]) == toupper(argv[1][i]))
                    {
                        printf("Key must not contain repeated alphabets.\n");
                        return 1;
                    }
                }
            }
          substitution(argv[1]);
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}
void substitution(string key)
{
   string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   string text = get_string("plaintext: ");
   printf("ciphertext: ");
   int n = strlen(text);

   for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < 26; i++)
        {
            if(islower(text[j]))
            {
                if(text[j] == tolower(alphabet[i]))
                {
                    printf("%c", tolower(key[i]));
                }
             }

            else
            {
                if(text[j] == toupper(alphabet[i]))
                {
                    printf("%c", toupper(key[i]));
                }
            }
        }

        if(!isalpha(text[j]))
        {
            printf("%c", text[j]);
        }
   }
   printf("\n");
}