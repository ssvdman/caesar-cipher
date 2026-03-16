#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string get_plain_text(void);
char rotate(char c, int n);

/* TODO
 get key using command line arguement, use of main(int argc, string argv[]).. should be like ./ceaser input. (done)
 adding more than one arguement will result in error message showing how to use it. usage: ./caesar key (done)
 make sure it only takes integers and not alphabets. use isdigit from ctype.h (done)
 the 'integer' u get from the user is actually a string bc argv[] is actually a string variable. so we have to convert this string input to integer.
 we can use atoi from #stdlib.h to convert string to int (done)

 get plain text using get_string (done)

 encipher the plaintext by rotating by given value. first rotate one char, ci = (pi + k) % 26 formula. (done)
 next rotate the whole string by rotating each char. use strlen to get length (done)

 print cypher text (done) */

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; argv[1][i] != '\0'; i++)            // checking every character in argv string till it reaches nul
        {
            if (isdigit(argv[1][i]))
            {
                //printf("%i\n", atoi(argv[1]));              // using atoi to convert the string from user to int
                //return 0;
            }
            else
            {
                printf("Usage: ./caesar key\n");            // give the error message if alphabet is given as input
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");                    // give the error message if more than 1 digit
        return 1;
    }

    string text = get_plain_text();                        // calling the plaintext function

    char ciphertext[strlen(text)+1];
    char result;
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        result = rotate(text[i], atoi(argv[1]));
        ciphertext[i] = result;
        printf("%c", result);
    }
    printf("\n");
}

string get_plain_text(void)                                   //function to get plaintext
{
    string plain_text = get_string("Plaintext:  ");
    return plain_text;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        int alphabetical_index_capital = c - 'A';                              // convert to alphabetical index (A=0)
        char ci = (alphabetical_index_capital + n) % 26;
        int ASCII_index_capital = ci + 'A';                             // convert back to ascii index
        return ASCII_index_capital;
    }
    else if (islower(c))
    {
        int alphabetical_index_lower = c - 'a';
        char ci = (alphabetical_index_lower + n) % 26;
        int ASCII_index_lower = ci + 'a';
        return ASCII_index_lower;
    }
    if (!isalpha(c))
    {
        return c;
    }

    return 0;
}
