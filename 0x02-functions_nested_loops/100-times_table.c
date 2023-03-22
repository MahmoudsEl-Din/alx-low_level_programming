#include "main.h"

/**
 * print_times_table - prints the n times table starting with 0
 * @n: the size of the times table to print
 */
void print_times_table(int n)
{
    if (n < 0 || n > 15)
        return;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int result = i * j;
            if (j == 0)
                printf("%d", result);
            else
                printf(",%4d", result);
        }
        printf("\n");
    }
}
