#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of listint_t list.
 * @head: Pointer to head of the list.
 * @index: Index of the node, starting at 0.
 *
 * Return: nth node, or NULL if node does not exist.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		if (count == index)
			return (current);

		current = current->next;
		count++;
	}

	return (NULL);
}
