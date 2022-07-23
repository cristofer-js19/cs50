#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float coin = 0.0f;
    int divider = 0;
    int result = 0;

    do
    {
        coin = get_float("Coin: ");
        int cents = round(coin * 100);

        const int size = 4;
        int baseCoinsList[size] = {25, 10, 5, 1};

        while (cents > 0)
        {
            if (cents >= baseCoinsList[divider])
            {
                if ((cents / baseCoinsList[divider]) > 0)
                {
                    result++;
                    cents -= baseCoinsList[divider];
                }
            }
            else
            {
                divider++;
            }
        }
        printf("%d\n", result);
        result = 0;
        divider = 0;
    }
    while (coin < 0);
}
