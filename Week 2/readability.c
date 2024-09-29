#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // Compute the Coleman-Liau index
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Print the grade level

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    int len = strlen(text);
    int count = 0;
    // Return the number of letters in text
    for (int i = 0; i < len; i++)
    {
        if (((text[i] >= 65) && (text[i] <= 90)) || ((text[i] >= 97) && (text[i] <= 122)))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{

    int len = strlen(text);
    int count = 0;

    // Return the number of words in text
    for (int i = 0; i < len; i++)
    {
        if (text[i] == 32)
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentences(string text)
{
    int len = strlen(text);
    int count = 0;
    // Return the number of sentences in text
    for (int i = 0; i < len; i++)
    {
        if ((text[i] == 33) || (text[i] == 46) || (text[i] == 63))
        {
            count++;
        }
    }
    return count;
}
