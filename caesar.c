#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool areTheArgumentsValid(int argc, string argv[]);

int main(int argc, string argv[])
{
    int key = 0;
    if (!areTheArgumentsValid(argc, argv))
    {
        return 1;
    }
    else
    {
        key = atoi(argv[1]);
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    int n = strlen(plaintext);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int asciiReference = isupper(plaintext[i]) ? 65 : 97;
            int alphabeticalIndex = ((int) plaintext[i]) - asciiReference;
            int remainder = (alphabeticalIndex + key) % 26;
            char cipherLetter = (char)(remainder + asciiReference);

            printf("%c", cipherLetter);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

bool areTheArgumentsValid(int argc, string argv[])
{
    bool isValid = true;
    string errorMsg = "Usage: ./caesar key\n";

    if (argc != 2)
    {
        printf("%s", errorMsg);
        isValid = false;
    }
    else
    {
        int n = strlen(argv[1]);
        for (int i = 0; i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("%s", errorMsg);
                isValid = false;
            }
        }
    }

    return isValid;
}
