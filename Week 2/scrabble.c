#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype
int compute_score(string word);

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Initialize score to zero
    int total_score = 0;

    // Loop through each character in the word
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        char c = word[i];

        // Check if the character is an uppercase letter
        if (isupper(c))
        {
            total_score += POINTS[c - 'A'];
        }
        // Check if the character is a lowercase letter
        else if (islower(c))
        {
            total_score += POINTS[c - 'a'];
        }
        // Ignore non-alphabetic characters
    }

    // Return the computed score
    return total_score;
}
