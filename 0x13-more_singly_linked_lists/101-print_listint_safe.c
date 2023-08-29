#include "lists.h"

/**
 * count_unique_nodes - Counts the number of unique nodes in a
 * looped listint_t linked list.
 * @head: Pointer to head of the list.
 *
 * Return: The number of unique nodes in the list, or 0 if otherwise.
 */

size_t count_unique_nodes(const listint_t *head)
{
	const listint_t *current = head;
	const listint_t *runner = head;
	size_t nodes = 0;

	if (head == NULL)
		return (0);

	while (runner && runner->next)
	{
		current = current->next;
		runner = runner->next->next;

		if (current == runner)
		{
			runner = head;
			while (current != runner)
			{
				nodes++;
				current = current->next;
				runner = runner->next;
			}

			do

			{
				nodes++;
				runner = runner->next;
			} while (current != runner);

			return (nodes);
		}
	}

	return (nodes);
}

/**
 * print_listint_safe - Prints a listint_t list.
 * @head: Pointer to head of the list.
 *
 * Return: Number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	size_t loop_length = count_unique_nodes(head);

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		nodes++;

		if (loop_length && nodes == loop_length)
		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;
		}

		head = head->next;
	}

	return (nodes);
}
