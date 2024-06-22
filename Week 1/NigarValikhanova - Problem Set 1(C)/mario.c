#include <cs50.h>
#include <stdio.h>

// We write the name of the function here to avoid errors
int get_height(void);
void print_row(int bricks);

int main(void)
{
    // We ask the user to get the height
    int height = get_height();

    // Print a pyramid of that height
    print_row(height);

    return 0;
}

// This function is for to get a valid height from the user

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    // we insist get the height between 1 and 8
    while (height < 1 || height > 8);
    return height;
}

void print_row(int bricks)
{
    // this is for the loop
    for (int i = 0; i < bricks; i++)
    {
        // print spaces
        for (int j = 0; j < bricks - i - 1; j++)
        {
            printf(" ");
        }

        // print bricks
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // And this is for moving to the next line
        printf("\n");
    }
}
