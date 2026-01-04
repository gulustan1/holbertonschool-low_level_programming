#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: a name to print
 * @f: a pointer to the function
 *
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
