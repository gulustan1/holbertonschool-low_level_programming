#include "main.h"

/**
 * _puts_recursion - Prints a string, followed by a new line
 * @s: The string to print
 */
void _puts_recursion(char *s)
{
	if (*s == '\0') /* Base case: if we reach the end of the string */
	{
		_putchar('\n'); /* Print a newline character */
		return;
	}
	_putchar(*s); /* Print the first character of the string */
	_puts_recursion(s + 1); /* Recursively call the function with the next character */
}
