#include "lists.h"
/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: poinyer to the head node
 * @n: data
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *last = *head;

	new_node = (dlistint_t *)malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;

	new_node->next = NULL;
	/*If the Linked List is empty, then make the new node as head*/
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	/*Else traverse till the last node*/
	while (last->next != NULL)
		last = last->next;

	/*Change the next of last node*/
	last->next = new_node;
	/*Make last node as previous of new node*/
	new_node->prev = last;

	return (new_node);
}
