#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number = get_long("Input the number "); //number of the card
    long clone_number = number;

    int second_to_last_sum = 0;
    int rest_sum = 0;
    int flag = 1; // which number it is

    while(number > 0)
    {
        int i = number % 10; //the last number

        if (flag % 2 != 0) // whether the number is even or not
        {
            rest_sum += i;
        }
        else
        {
            if (i * 2 >= 10)
            {
                second_to_last_sum += (i * 2) % 10;
                second_to_last_sum += (i * 2) / 10;
            }
            else
            {
                second_to_last_sum += i * 2;
            }
        }
        number = number / 10; //gets rid of the last number
        flag++; //next number
    }

    flag = flag - 1;
    for(int k = 0; k < flag - 2; k++) //first 2 numbers
    {
        clone_number = clone_number / 10;
    }

    if ((second_to_last_sum + rest_sum) % 10 == 0)
    {
        if ((clone_number == 34 || clone_number == 37) && flag == 15)
        {
            printf("AMEX\n");
        }
        else if ((clone_number == 51 || clone_number == 52 || clone_number == 53 || clone_number == 54 || clone_number == 55) && flag == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (clone_number / 10 == 4 && (flag == 13 || flag == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}


