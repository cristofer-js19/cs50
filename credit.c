#include <stdio.h>
#include <cs50.h>

int firstDigit(long number)
{
    while (number >= 10)
    {
        number /= 10;
    }
    return number;
}

string defineCreditCard(bool hasDigitSumValid, int firstDigitCard, int totalDigits)
{
    string result = "INVALID\n";

    if (hasDigitSumValid)
    {
        if (firstDigitCard == 3 && totalDigits == 15)
        {
            result = "AMEX\n";
        }
        else if (firstDigitCard == 4 && (totalDigits >= 13 && totalDigits <= 16))
        {
            result = "VISA\n";
        }
        else if (firstDigitCard == 5 && totalDigits == 16)
        {
            result = "MASTERCARD\n";
        }
    }
    return result;
}

int main(void)
{
    long cardNumber = get_long("Credit Card Number:");
    int firstDigitCard = firstDigit(cardNumber);
    long reducedCardNumber = 0L;
    int remainder = 0;
    bool everyOtherNumber = false;
    int totalEveryOtherNumber = 0;
    int totalNotEveryOtherNumber = 0;
    int totalDigits = 0;

    do
    {
        remainder = cardNumber % 10;
        reducedCardNumber = cardNumber / 10;

        if (everyOtherNumber)
        {
            int finalRemainder = remainder * 2;
            if (finalRemainder == 10)
            {
                totalEveryOtherNumber += 1;
            }
            if (finalRemainder > 10)
            {
                totalEveryOtherNumber += 1;
                totalEveryOtherNumber += finalRemainder - 10;
            }
            else
            {
                totalEveryOtherNumber += finalRemainder;
            }
            everyOtherNumber = false;
        }
        else
        {
            totalNotEveryOtherNumber += remainder;
            everyOtherNumber = true;
        }

        cardNumber = reducedCardNumber;
        totalDigits++;
    }
    while (reducedCardNumber > 0);

    printf("%s", defineCreditCard((((totalEveryOtherNumber + totalNotEveryOtherNumber) % 10) == 0), firstDigitCard, totalDigits));
}
