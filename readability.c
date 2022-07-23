#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int calculateIndex(int totalLetters, int totalWords, int totalSentences);
void printGrade(int index);

int main(void)
{
    int totalLetters = 0;
    int totalWords = 1;
    int totalSentences = 0;

    string text = get_string("Text: ");

    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isspace(text[i]))
        {
            totalWords++;
        }

        if (isalpha(text[i]))
        {
            totalLetters++;
        }

        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            totalSentences++;
        }
    }

    int index = calculateIndex(totalLetters, totalWords, totalSentences);
    printGrade(index);
}

int calculateIndex(int totalLetters, int totalWords, int totalSentences)
{
    float avgLetters = (0.0588 * (((totalLetters / (float)totalWords)) * 100));
    float avgSentences = (0.296 * (((totalSentences / (float)totalWords)) * 100));
    return (int) roundf(avgLetters - avgSentences - 15.8);
}

void printGrade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade ");
        printf("%i", index);
    }
    printf("\n");
}
