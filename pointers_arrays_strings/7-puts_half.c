#include <stdio.h>
#include "main.h"

/**
 * puts_half - prints the half of a string
 * @str: a string variable to print its half
 *
 * Return: void
 */

void puts_half(char *str)
{
	int n;
	int i;
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	i = len - 1;

	if (len % 2 == 0)
		n = len / 2;
	if (len % 2 == 1)
		n = (len + 1) / 2;

	while (n <= i)
	{
		_putchar(str[n]);
		n++;
	}
	_putchar('\n');
}
