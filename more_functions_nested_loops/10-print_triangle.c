#include <stdio.h>
#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: the size of a triangle
 *
 * Return: void
 */

void print_triangle(int size)
{
	int i;
	int j;
	int h;

	if (size <= 0)
		_putchar('\n');

	for (i = 1; i <= size; i++)
	{
		for (j = 1; j < size - i + 1; j++)
			_putchar(' ');
		for (h = 0; h < i; h++)
			_putchar('#');
		_putchar('\n');
	}

}

