#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the hash table.
 *
 * Return: Pointer to the newly created hash table, or NULL if it fails.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;

	if (size == 0)
		return (NULL);

	new_table = calloc(1, sizeof(shash_table_t));
	if (!new_table)
		return (NULL);

	new_table->size = size;
	new_table->array = calloc(size, sizeof(shash_node_t *));

	if (!new_table->array)
	{
		free(new_table);
		return (NULL);
	}

	return (new_table);
}

/**
 * insert_sorted - Inserts a new node in a sorted linked list.
 * @ht: Pointer to the sorted hash table.
 * @new_node: Pointer to the new node to insert.
 *
 * Return: Nothing.
 */

void insert_sorted(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *current = ht->shead;

	if (current == NULL)
	{
		ht->shead = ht->stail = new_node;
		new_node->snext = new_node->sprev = NULL;
		return;
	}

	while (current)
	{
		if (strcmp(new_node->key, current->key) < 0)
		{
			new_node->snext = current;
			new_node->sprev = current->sprev;

			if (!current->sprev)
				ht->shead = new_node;
			else
				current->sprev->snext = new_node;
			current->sprev = new_node;
			return;
		}
		current = current->snext;
	}

	new_node->sprev = ht->stail;
	new_node->snext = ht->stail->snext;
	ht->stail->snext = new_node;
	ht->stail = new_node;
}

/**
 * shash_table_set - Adds an element to the sorted hash table.
 * @ht: Pointer to the sorted hash table to which the element is added.
 * @key: The key of the element to add.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, or 0 otherwise.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node;
	unsigned long int hash_index = 0;
	char *new_value, *new_key;

	if (!ht || !key || !*key || !value)
		return (0);
	new_value = strdup(value);
	if (!new_value)
		return (0);
	hash_index = key_index((const unsigned char *)key, ht->size);

	while (ht->array[hash_index])
	{
		if (!strcmp(key, ht->array[hash_index]->key))
		{
			free(ht->array[hash_index]->value);
			ht->array[hash_index]->value = new_value;
			return (1);
		}
		ht->array[hash_index] = ht->array[hash_index]->next;
	}

	new_node = calloc(1, sizeof(shash_node_t));
	if (!new_node)
	{
		free(new_value);
		return (0);
	}
	new_key = strdup(key);
	if (!new_key)
		return (0);

	new_node->key = new_key;
	new_node->value = new_value;
	new_node->next = ht->array[hash_index];
	ht->array[hash_index] = new_node;
	insert_sorted(ht, new_node);
	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key in a sorted
 * hash table.
 * @ht: Pointer to the sorted hash table.
 * @key: The key for which to retrieve the value.
 *
 * Return: Value associated with the key, or NULL if the key does not exist.
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	while (ht->array[index])
	{
		if (!strcmp(key, ht->array[index]->key))
			return (ht->array[index]->value);
		ht->array[index] = ht->array[index]->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a hash table.
 * @ht: The pointer to the hash table.
 *
 * Return: Nothing.
 *
 */

void shash_table_print(const shash_table_t *ht)
{
	int printed = 0;
	shash_node_t *item = ht->shead;

	if (!ht)
		return;

	printf("{");

	while (item)
	{
		if (printed)
			printf(", ");
		printf("'%s': '%s'", item->key, item->value);
		printed = 1;
		item = item->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a hash table in reverse.
 * @ht: The pointer to the hash table.
 *
 * Return: Nothing.
 *
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *item = ht->stail;
	int printed = 0;

	if (!ht)
		return;

	printf("{");

	while (item)
	{
		if (printed)
			printf(", ");
		printf("'%s': '%s'", item->key, item->value);
		printed = 1;
		item = item->sprev;
	}

	printf("}\n");
}


/**
 * sfree_item - Frees memory occupied by a hash table item.
 * @item: A pointer to the hash node to be freed.
 *
 * Return: Nothing
 */

void sfree_item(shash_node_t *item)
{

	free(item->key);
	free(item->value);
	free(item);
}

/**
 * shash_table_delete - Deletes a hash table.
 * @ht: The pointer to hash table.
 *
 * Return: Nothing
 */

void shash_table_delete(shash_table_t *ht)
{
	unsigned int i;
	shash_node_t *item, *next;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		item = ht->array[i];
		while (item)
		{
			next = item->next;
			sfree_item(item);
			item = next;
		}
	}

	free(ht->array);
	free(ht);
}
