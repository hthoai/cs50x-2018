#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // Check if lack of argv[1]
    if (argc != 2)
    {
        return 1;
    }
    //Check if keyword contains number character
    int key_len = strlen(argv[1]);  // argv[1] contains keyword
    for (int i = 0; i < key_len; i++)
    {
        char ch = toupper(argv[1][i]);
        if (ch < 'A' || ch > 'Z')
        {
            return 1;
        }
    }
    // Get plaintext from user
    int key = 0;
    int key_char;
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Encrypt plaintext
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // Back to the 1st character in keyword if key is over keyword's length
        if (key == key_len)
        {
            key = 0;
        }
        key_char = toupper(argv[1][key]) - 'A';

        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", ((plaintext[i] - 'a' + key_char) % 26) + 'a');
            key++;
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", ((plaintext[i] - 'A' + key_char) % 26) + 'A');
            key++;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}