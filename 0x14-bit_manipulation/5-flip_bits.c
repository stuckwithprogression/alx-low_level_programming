#include "main.h"

/**
 * flip_bits - tallies the number of bits to change
 * to get from one number to another and or vice/versa
 * @n: first number
 * @m: second number
 * Return: will return number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, y = 0;
	unsigned long int current;
	unsigned long int xor = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		current = xor >> x;
		if (current & 1)
			y++;
	}

	return (y);
}
