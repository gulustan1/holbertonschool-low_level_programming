#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node - adds a new node to the list
 * @head: pointer to pointer to head
 * @str: a string
 *
 * Return: address of the new node
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len;

	if (head == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	new->len = len;
	new->next = *head;
	*head = new;
	return (new);
}
