#include "main.h"

/**
* print_binary - function displays the binary representation of a given number.
* @n: the number to be printed in binary form
* Return: nothing
*/

void print_binary(unsigned long int n)
{
	int x, y = 0;
	unsigned long int current;

	for (x = 63; x >= 0; x--)
	{
		current = n >> x;

		if ((current & 1) == 1)
		{
			_putchar('1');
			y++;
		}
		else if (y != 0)
			_putchar('0');
	}
	if (y == 0)
		_putchar('0');
}
