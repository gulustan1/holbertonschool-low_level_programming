#include <stdio.h>
#include "main.h"

/**
 * print_line - prints a straight line in the terminal
 * @n: the number of times _ should be printed
 *
 * Return: void
 */

void print_line(int n)
{
	int i = 0;

	while (i < n)
	{
		_putchar('_');
		i++;
	}
	_putchar('\n');
}

