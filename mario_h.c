#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Positive Number: ");

        for (int i = 1; i <= height; i++)
        {
            for (int j = height; j >= 1; j--)
            {
                printf((i >= j) ? "#" : " ");
            }

            printf("  ");

            for (int j = height; j >= 1; j--)
            {
                if (i >= j)
                {
                    printf("#");
                }
            }
            printf("\n");
        }
    }
    while (!(height >= 1 && height < 9));
}
