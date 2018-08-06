#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // Check if lack of argv[1]
    if (argc != 2)
    {
        return 1;
    }

    string plaintext;
    int key = 0;
    int factor = 1;

    // Get plaintext from user
    plaintext = get_string("plaintext: ");

    // Convert key from number string to integer
    for (int i = strlen(argv[1]) - 1; i >= 0; i--)
    {
        key += (argv[1][i] - '0') * factor;
        factor *= 10;
    }

    printf("ciphertext: ");

    // Encrypt plaintext
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", ((plaintext[i] - 'a' + key) % 26) + 'a');
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", ((plaintext[i] - 'A' + key) % 26) + 'A');
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}