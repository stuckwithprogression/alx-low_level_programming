#include "lists.h"

/**
 * free_listint - Frees a listint_t list.
 * @head: Pointer to head of the list.
 *
 * Return: Nothing.
 */

void free_listint(listint_t *head)
{
	listint_t *temp;
	listint_t *current = head;

	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
