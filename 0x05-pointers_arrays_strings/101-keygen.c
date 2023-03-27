#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - entry point of the program
 *
 * Return: always 0
 */
int main(void)
{
    int i, sum, diff, c;
    char password[100];

    srand(time(NULL)); /* seed the random number generator */

    /* generate a random password */
    for (i = 0, sum = 0; sum < (2772 - 122); i++)
    {
        c = rand() % 62;
        if (c < 10)
            password[i] = '0' + c;
        else if (c < 36)
            password[i] = 'a' + c - 10;
        else
            password[i] = 'A' + c - 36;
        sum += password[i];
    }
    diff = sum - 2772 + 122;
    password[i++] = diff / 2;
    password[i] = '\0';

    /* print the generated password */
    printf("%s", password);

    return (0);
}
