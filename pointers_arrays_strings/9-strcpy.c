#include <stdio.h>
#include "main.h"

/**
 * *_strcpy - copy the string pointed by src
 * @src: string to be pointed
 * @dest: string to write copied src
 *
 * Return: char
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
