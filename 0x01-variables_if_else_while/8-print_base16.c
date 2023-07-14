#include <stdio.h>

/**
 * main - Print numbers between 0 to 9 and letters between a to f.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 28; i < 38; i++)
	{
		putchar(i);
	}
	for (i = 99; i < 105; i++)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}

