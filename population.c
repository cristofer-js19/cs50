#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int startSize = 0;
    int endSize = 0;
    int years = 0;

    do
    {
        startSize = get_int("Start Size:");
        int sizeGap = startSize;

        if (startSize >= 9)
        {
            do
            {
                endSize = get_int("End Size:");
                while (sizeGap < endSize)
                {
                    sizeGap += ((sizeGap / 3) - (sizeGap / 4));
                    years++;
                }
            }
            while (endSize < startSize);

            printf("Years: %i", years);
        }
    }
    while (startSize < 9);
}
