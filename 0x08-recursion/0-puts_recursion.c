#include "main.h"

/**
 * _puts_recursion - a function that prints a string, followed by a new line.
 * @s: String to print
 * Return: string printed
**/

void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(++s);
	}

	else
		_putchar('\n');
}
