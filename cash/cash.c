#include <stdio.h>
#include <cs50.h>
#define EPSILON 0.001

int cashier(float cash);

int main(void)
{
    float cash;

    do
    {
        cash = get_float("Change owed: ");
    }
    while (cash < 0); // Check if cash is negative

    printf("%d\n", cashier(cash));
}

int cashier(float cash)
{
    // The number of coins
    int coin = 0;
    // Convert dollar to cent
    int cent = (int)((cash + EPSILON) * 100);

    // Compute number of quarters
    if (cent >= 25)
    {
        coin += cent / 25;
        cent %= 25;
    }

    // Compute number of dimes
    if (cent >= 10)
    {
        coin += cent / 10;
        cent %= 10;
    }

    // Compute number of nickels
    if (cent >= 5)
    {
        coin += cent / 5;
        cent %= 5;
    }

    // Return result: total coins plus number of pennies
    return coin + cent;
}