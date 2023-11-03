#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table.
 * @key: The key string.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	/* Get the index where the key/value pair should be stored */
	index = key_index((unsigned char *)key, ht->size);
	/*Check for collision by iterating thru the linked list at the index*/
	current = ht->array[index];
	while (current != NULL)
	{
		/* If key already exists, update the value and return */
		if (strcmp(current->key, key) == 0)
		{
			free(current->value); /* free existing value */
			/* duplicate and set new value */
			current->value = strdup(value);
			if (current->value == NULL)
				return (0); /* strdup failed */
			return (1); /* success */
		}
		current = current->next;
	}
	/* If no collision or key doesn't exist, add a new node at beginning*/
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	/* Add the new node at the beginning of the linked list */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1); /* success */
}
