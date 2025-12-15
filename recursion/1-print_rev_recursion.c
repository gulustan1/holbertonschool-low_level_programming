#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse
 * @s: The string to print in reverse
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0') /* Base case: If we reach the end of the string */
	{
		return;
	}
	_print_rev_recursion(s + 1); /* Recursively move to the next character */
	_putchar(*s); /* Print the current character after the recursive call */
}
