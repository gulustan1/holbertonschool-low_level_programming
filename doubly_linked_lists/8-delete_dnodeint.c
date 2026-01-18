#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete, starting at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* Case 1: Deleting the head node (index 0) */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Traverse to the node at the specified index */
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	/* Case 2: Index is out of bounds */
	if (current == NULL)
		return (-1);

	/* Case 3: Deleting a node in the middle or at the end */
	/* Link the previous node to the next one */
	if (current->prev != NULL)
		current->prev->next = current->next;

	/* Link the next node back to the previous one (if not at the end) */
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
