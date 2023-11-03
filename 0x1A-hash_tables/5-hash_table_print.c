#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table.
 *
 * Return: Nothing
 *
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int hash_index;
	int printed = 0;

	if (!ht)
		return;

	printf("{");

	for (hash_index = 0; hash_index < ht->size; hash_index++)
	{
		if (ht->array[hash_index])
		{
			if (printed)
				printf(", ");
			printf("'%s' : '%s'", ht->array[hash_index]->key,
				   ht->array[hash_index]->value);
			printed = 1;
		}
	}
	printf("}\n");
}
