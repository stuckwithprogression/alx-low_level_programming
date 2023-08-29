#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n) of listint_t list.
 * @head: Pointer to head of the list.
 *
 * Return: sum of all the data (n), or 0 if otherwise.
 */

int sum_listint(listint_t *head)
{
	listint_t *current = head;
	int sum = 0;

	if (current == NULL)
		return (0);

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
