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
    for (int i = height; i > 0; i--)
    {

        // Print spaces for left side
        for (int j = 0; j < i - 1; j++)
        {
            printf(" ");
        }

        // Print hashes for left side
        for (int j = 0; j < height - i + 1; j++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        //Print hashes for right side
        for (int j = 0; j < height - i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}