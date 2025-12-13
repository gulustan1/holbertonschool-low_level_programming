#include <stdio.h>
#include "main.h"

/**
 * reverse_array - reverses array
 * @a: an array of integers
 * @n: the number of integers to swap
 *
 * Return: void
 */

void reverse_array(int *a, int n)
{
	int i = 0;
	int temp;

	while (i < n / 2)
	{
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
		i++;
	}

}
