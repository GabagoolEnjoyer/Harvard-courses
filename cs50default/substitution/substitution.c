#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool key_alphabetic(string key);
bool key_length(string key);
bool key_unique(string key);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Use only one key.\n");
        return 1;
    }

    string key = argv[1]; //takes user prompt from console

    if (key_alphabetic(key) && key_length(key) && key_unique(key)) //if flags then pass else error
    {

        string plaintext = get_string("plaintext: ");//user input of the text
        string ciphertext = plaintext;//duplicate that is going to be changed into cipher

        for(int i = 0, len = strlen(ciphertext); i < len; i++)
        {
            if isalpha(plaintext[i]) //if its alpha then it determines wheter its uppercase or not
            {
                if isupper(plaintext[i])//if it is than ascii is corrected accordingly and the result is changed to uppercase
                {
                    ciphertext[i] = toupper(key[plaintext[i] - 'A']);
                }
                else
                {
                    ciphertext[i] = tolower(key[plaintext[i] - 'a']);
                }

            }
        }
        printf("ciphertext: %s\n", ciphertext);
    }
    else //errors
    {
        if (!(key_alphabetic(key)))
        {
            printf("There are symbols other than letters.\n");
        }
        else if (!(key_length(key)))
        {
            printf("The size of the key is not 26. \n");
        }
        else if (!(key_unique(key)))
        {
            printf("There are symbols which are not unique. \n");
        }

        return 1;
    }
}

bool key_alphabetic(string key) //check if its all letters
{
    for(int i = 0, len = strlen(key); i < len; i++)
    {
        if (!(isalpha(key[i])))
        {
            return false;
        }
    }
    return true;
}

bool key_length(string key) //check if its 26 letters
{
    if (strlen(key) == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool key_unique(string key) //check if all letters are unique
{
    for(int i = 0, len = strlen(key); i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}
