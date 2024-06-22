#include <cs50.h>
#include <stdio.h>

// Function prototypes
int calculate_coins(int *cents, int coin_value);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    // Calculate the number of quarters, dimes, nickels, and pennies
    int quarters = calculate_coins(&cents, 25);
    int dimes = calculate_coins(&cents, 10);
    int nickels = calculate_coins(&cents, 5);
    int pennies = calculate_coins(&cents, 1);

    // Sum the number of quarters, dimes, nickels, and pennies used
    int sum = quarters + dimes + nickels + pennies;

    // Print that sum
    printf("%i\n", sum);
}

int calculate_coins(int *cents, int coin_value)
{
    // Calculate how many coins of a given value should be given
    int coins = *cents / coin_value;
    *cents = *cents % coin_value;
    return coins;
}
