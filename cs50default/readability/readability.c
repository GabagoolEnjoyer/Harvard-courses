#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int letters_counter(string text);
int words_counter(string text);
int sentence_counter(string text);
float l_finder(int words, int letters);
float s_finder(int sentences, int words);

int main(void)
{
    //input the string
    string text = get_string("Input the text: ");
    int text_letters_counter = letters_counter(text);
    int text_words_counter = words_counter(text);
    int text_sentence_counter = sentence_counter(text);
    float index = round(0.0588 * l_finder(text_words_counter, text_letters_counter) - 0.296 * s_finder(text_sentence_counter, text_words_counter) - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }
}

int letters_counter(string text)
{
    int letters = 0;
    for(int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalnum(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int words_counter(string text) //функция для подсчета слов
{
    int words_counter = 0;
    for(int i = 0, len = strlen(text); i < len; i++)
    {
        if(i + 1 < len)//so that it doesnt go out of boundaries
        {
            if (isalnum(text[i]) && !isalnum(text[i+1]))//current symbol is char and next is not = the word ended
            {
                words_counter += 1;
            }
        }
    }
    return words_counter;
}

int sentence_counter(string text)
{
    int sentence_counter = 0;
    for(int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_counter += 1;
        }
    }
    return sentence_counter;
}

float l_finder(int words, int letters)
{
    return round(((float)letters / (float) words) * 100);
}

float s_finder(int sentences, int words)
{
    return round(((float)sentences / (float) words) * 100);
}
