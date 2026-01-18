#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node to the end
 * @head: a pointer to the head of the list
 * @n: int
 *
 * Return: the address of the new element
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *temp;

	if (head == NULL)
	{
		return (NULL);
	}

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		return (NULL);
	}

	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
		new->n = n;
		return (new);
	}



	temp = *head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	new->n = n;
	new->prev = temp;
	temp->next = new;
	new->next = NULL;

	return (new);
}

