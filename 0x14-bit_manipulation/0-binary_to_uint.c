#include "main.h"

/**
* binary_to_uint - a function that converts a binary number to an unsigned int
* @bin: is a string of binary numbers
* Return: will return an unsigned int after conversion
*/

unsigned int binary_to_uint(const char *bin)
{
	unsigned int a = 0, b = 0;

	if (!bin)
		return (0);

	while (bin[a])
	{
		if (bin[a] == '0' || bin[a] == '1')
		{
			b <<= 1;
			b += bin[a] - '0';
			a++;
		}
		else
			return (0);
	}
	return (b);
}
