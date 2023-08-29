#include "lists.h"

/**
 * listint_len - Prints the number of elements in a linked listint_t list.
 * @h: Pointer to list.
 *
 * Return: Number of nodes.
 */

size_t listint_len(const listint_t *h)
{
	size_t dig = 0;

	while (h != NULL)
	{
		dig++;
		h = h->next;
	}
	return (dig);
}
