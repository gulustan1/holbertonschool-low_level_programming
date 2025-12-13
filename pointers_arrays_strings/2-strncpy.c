#include <stdio.h>
#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: the first string
 * @src: the second string
 * @n: the number of elements
 *
 * Return: char
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
