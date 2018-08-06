#include <stdio.h>
#include <string.h>

#define ALPHA_LEN 53

#define _XOPEN_SOURCE
#include <unistd.h>

char *crypt(const char *key, const char *salt);

int main(int argc, char const *argv[])
{
    // Check if lack of hash or over-argument
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    const char *hash_given = argv[1];
    char salt[3];
    // Copy the first two characters of hash given to salt
    // Because they represent the salt itself
    memcpy(salt, hash_given, 2);

    char password[5];
    char alphabet[] = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Create 5 loop nested loop to generate password whose length is from 1 to 5
    // In case password has 1/2/3/4 character(s)
    // character at position 2/3/4/5 will be '\0'
    for (int i5 = 0; i5 < ALPHA_LEN; i5++)
    {
        for (int i4 = 0; i4 < ALPHA_LEN; i4++)
        {
            for (int i3 = 0; i3 < ALPHA_LEN; i3++)
            {
                for (int i2 = 0; i2 < ALPHA_LEN; i2++)
                {
                    for (int i1 = 1; i1 < ALPHA_LEN; i1++)
                    {
                        password[0] = alphabet[i1];
                        password[1] = alphabet[i2];
                        password[2] = alphabet[i3];
                        password[3] = alphabet[i4];
                        password[4] = alphabet[i5];

                        //Compare hash given vs hash generated
                        if (strcmp(crypt(password, salt), hash_given) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}