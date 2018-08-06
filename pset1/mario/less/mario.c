#include <stdio.h>
#include <cs50.h>

void draw(int height);

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23); // Check user input
    draw(height);
}

void draw(int height)
{
    // Initialize hash value by 2
    int hashes = 2;

    for (int i = height; i > 0; i--)
    {

        // Print spaces
        for (int j = 0; j < i - 1; j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int k = 0; k < hashes; k++)
        {
            printf("#");
        }

        hashes++;
        printf("\n");
    }
}