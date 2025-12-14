#include <stdio.h>
#include "main.h"

/**
 * leet - encodes a string to 1337
 * @str: a string
 *
 * Return: char
 */

char *leet(char *str)
{
	int i;
	int j;
	char num[] = "4433007711";
	char let[] = "aAeEoOtTlL";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; let[j] != '\0'; j++)
		{
			if (str[i] == let[j])
			{
				str[i] = num[j];
			}
		}
	}

	return (str);
}
