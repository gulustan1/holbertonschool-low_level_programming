#include <stdio.h>
#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the number of elements to be appended from src
 *
 * Return: char
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (j <  n && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}

	dest[i + j] = '\0';

	return (dest);
}
