#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * dlistint_len - returns the len of the list
 * @h: pointer to the head of the list
 *
 * Return: length of list
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		len++;
		h = h->next;
	}
	return (len);
}
