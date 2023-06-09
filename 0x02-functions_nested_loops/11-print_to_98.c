#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - Entry point.
 *
 * @a: The integer
 * Description: prints all natural numbers from n to 98, followed by a new line
 * Return: int
 */
void print_to_98(int a)
{
	while (a != 98)
	{
		printf("%i, ", a);
		if (a > 98)
		{
			a--;
		}
		else
		{
			a++;
		}
	}
	printf("98\n");
}
