#import <cs50.h>
#import <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("input the height ");
    }
    while (n < 1 || n >= 9);

    int space_count = n - 1;
    int hashes = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < space_count; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < hashes; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int l = 0; l < hashes; l++)
        {
            printf("#");
        }

        printf("\n");
        hashes++;
        space_count--;
    }
}
