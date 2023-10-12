#include "lists.h"
/**
 * add_dnodeint -  adds a new node at the beginning of a dlistint_t list
 * @head: pointer to the head node
 * @n: data in the node
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	/*allocate the node*/
	new_node = (dlistint_t *)malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	/*put node in the data, wher n i new data*/
	new_node->n = n;

	new_node->next = (*head);
	new_node->prev = NULL;
	/*change previous head node to new node*/
	if ((*head) != NULL)
	{
		(*head)->prev = new_node;
	}
	/*move head to point to the new node*/
	(*head) = new_node;

	return (new_node);
}
