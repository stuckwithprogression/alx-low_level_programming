#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given position
 * @head: Double pointer to head of the list.
 * @index: Index of the list where the node should be deleted,
 * starting at zero.
 *
 * Return: Address of new node, or NULL if it fails.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head;
	listint_t *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	for (i = 0; current != NULL && i < index - 1; i++)
		current = current->next;

	if (current == NULL || current->next == NULL)
		return (-1);

	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}
