#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char cipher_char = rotate(plaintext[i], key);
        printf("%c", cipher_char);
    }

    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    char p = c;

    if (isalpha(c))
    {
        if (isupper(c))
        {
            p = ((c - 'A' + n) % 26) + 'A';
        }
        else if (islower(c))
        {
            p = ((c - 'a' + n) % 26) + 'a';
        }
    }
    return p;
}
