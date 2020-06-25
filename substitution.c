#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int testcase = 0;

    //printf("key has %d characters.\n", num_characters);

    if (argc != 2)
    {
        printf("Error. Please try again and enter a valid key.\n");
        return 1;
    }

    int num_characters = strlen(argv[1]);

    if (num_characters == 26)
    {
        for (int i = 0; i <= 25; i++)
        {
            if (islower(argv[1][i]) || isupper(argv[1][i]))
            {
                testcase++;
            }
            else
            {
                printf("Error. Please try again and enter a valid key.\n");
                return 1;
            }
        }
        for (int n = 0; n <= 25; n++)
        {
            int o = n + 1;
            while (argv[1][o] != '\0')
            {
                if (argv[1][n] == argv[1][o])
                {
                    printf("Error. Please try again and enter a valid key.\n");
                    return 1;
                }
                o++;
            }
        }
    }
    else
    {
        printf("Error. Please try again and enter a valid key.\n");
        return 1;
    }

    // printf("testcase is %d.\n", testcase);

    // actual program begins once all errors in key input is checked for
    if (testcase == 26)
    {

        char alphlower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        char alphupper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        string plaintext = get_string("plaintext: ");
        int ptxtlength = strlen(plaintext);
        int templettervalue[ptxtlength];
        char templetters[ptxtlength];
        char cyphertext[ptxtlength];

        // printf("plantext is %d char long\n", ptxtlength);

        for (int j = 0; j <= ptxtlength - 1; j++)
        {
            for (int k = 0; k <= 25; k++)
            {
                if (plaintext[j] == alphlower[k] || plaintext[j] == alphupper[k])
                {
                    templettervalue[j] = k + 1;
                }
                else
                {
                    templetters[j] = plaintext[j];
                }
            }
        }

        for (int m = 0; m < ptxtlength; m++)
        {
            if (isupper(templetters[m]))
            {
                templetters[m] = toupper(argv[1][templettervalue[m] - 1]);
            }
            else if (islower(templetters[m]))
            {
                templetters[m] = tolower(argv[1][templettervalue[m] - 1]);
            }
        }

        for (int l = 0; l < ptxtlength; l++)
        {
            if (isspace(plaintext[l]) || isdigit(plaintext[l]) || ispunct(plaintext[l]))
            {
                cyphertext[l] = plaintext[l];
            }
            else
            {
                cyphertext[l] = templetters[l];
            }
        }



        // for (int loop = 0; loop < ptxtlength; loop++)
        // {
        //     printf("%d ", templettervalue[loop]);
        // }
        printf("ciphertext: ");
        for (int looop = 0; looop < ptxtlength; looop++)
        {
            printf("%c", cyphertext[looop]);
        }
        printf("\n");
    }



}