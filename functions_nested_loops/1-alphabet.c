#include "main.h"

/**
 * print_alphabet - Prints the alphabet in lowercase, followed by a new line.
 *
 * Description: Uses _putchar only twice in the function's source code 
 * (one in the loop, one for the newline).
 *
 * Return: void
 */
void print_alphabet(void)
{
	char letter = 'a';

	/* * Use a loop to print all 26 characters. 
	 * This is the first usage of the _putchar statement.
	 */
	while (letter <= 'z')
	{
		_putchar(letter);
		letter++;
	}

	/* * Print a newline character. 
	 * This is the second usage of the _putchar statement.
	 */
	_putchar('\n');
}

