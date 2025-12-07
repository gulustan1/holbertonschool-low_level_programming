#include <stdio.h>
#include "main.h"

/**
 * more_numbers - prints 10 times the numbers from 0 to 14
 *
 * Return: void
 */

void more_numbers(void)
{
	int a;
	int n;

	a = 0;
	while (a < 10)
	{
		n = 0;
		while (n <= 14)
		{
			if (n >= 10)
				_putchar('1');
			_putchar((n % 10) + '0');
			n++;
		}
		_putchar('\n');
		a++;
	}
}

