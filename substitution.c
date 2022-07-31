#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool areTheArgumentsValid(int argc, string argv[]);
bool wasItTheKeyInformed(int argc);
bool doesTheKeyHaveCorrectNumberOfCharacters(string key);
bool doesTheKeyContainOnlyAlphabeticCharacters(string key);
bool doesNotTheKeyContainRepeatedCharacters(string key);

int main(int argc, string argv[])
{
    if (!areTheArgumentsValid(argc, argv))
    {
        return 1;
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

            char cipherCharacter = argv[1][alphabeticalIndex];
            printf("%c", (asciiReference == 65) ? toupper(cipherCharacter) : tolower(cipherCharacter));
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
    if (!wasItTheKeyInformed(argc))
    {
        return false;
    }
    if (!doesTheKeyHaveCorrectNumberOfCharacters(argv[1]))
    {
        return false;
    }
    if (!doesTheKeyContainOnlyAlphabeticCharacters(argv[1]))
    {
        return false;
    }
    if (!doesNotTheKeyContainRepeatedCharacters(argv[1]))
    {
        return false;
    }

    return true;
}

bool wasItTheKeyInformed(int argc)
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }
    return true;
}

bool doesTheKeyHaveCorrectNumberOfCharacters(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    return true;
}

bool doesTheKeyContainOnlyAlphabeticCharacters(string key)
{
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
    }
    return true;
}

bool doesNotTheKeyContainRepeatedCharacters(string key)
{
    int totalAsciiCodeSum = 2015;
    int totalAsciiKeyCodeSum = 0;

    for (int i = 0; i < 26; i++)
    {
        totalAsciiKeyCodeSum += (int)(toupper(key[i]));
    }

    if (totalAsciiKeyCodeSum != totalAsciiCodeSum)
    {
        printf("Key must not contain repeated characters.\n");
        return false;
    }
    return true;
}
