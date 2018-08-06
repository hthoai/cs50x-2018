#include <stdio.h>
#include <string.h>
#include <cs50.h>

#define TYPESIZ 11

void checksum(long long numbers);

int main(void)
{
    long long numbers;

    do
    {
        numbers = get_long_long("Number: ");
    }
    while (numbers < 0);

    checksum(numbers);
}

void checksum(long long numbers)
{
    int sum = 0;
    char type[TYPESIZ];

    // Check if it is VISA's starting number
    if ((numbers >= 4000000000000 && numbers < 5000000000000) ||
        (numbers >= 4000000000000000 && numbers < 5000000000000000))
    {
        strcpy(type, "VISA");
    }
    // Check if it is AMEX's starting numbers
    else if ((numbers >= 340000000000000 && numbers < 350000000000000) ||
             (numbers >= 370000000000000 && numbers < 380000000000000))
    {
        strcpy(type, "AMEX");
    }
    // Check if it is MASTERCARD's starting numbers
    else if (numbers >= 5100000000000000 && numbers < 5600000000000000)
    {
        strcpy(type, "MASTERCARD");
    }
    // Case it's invalid
    else
    {
        printf("INVALID\n");
        return;
    }

    // Check if credit card number is valid according to Luhn’s algorithm
    // Multiply every other digit by 2, starting with the number’s second-to-last digit
    // And then add those products' digits to the sum
    for (long long i = numbers / 10; i > 0; i /= 100)
    {
        long long temp = 2 * (i % 10);
        sum += (temp / 10) + (temp % 10);
    }

    // Add the sum to the sum of the digits that weren’t multiplied by 2
    for (long long i = numbers; i > 0; i /= 100)
    {
        sum += (i % 10);
    }

    // Check if the total’s last digit is 0 (valid)
    if (sum % 10 == 0)
    {
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
}