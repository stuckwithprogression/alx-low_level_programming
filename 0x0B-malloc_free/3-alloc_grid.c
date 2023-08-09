#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - function to make a grid
 * @width: width of the grid
 * @height: height of the grid
 * Return: pointer to 2dimensional array
 */

int **alloc_grid(int width, int height)
{
	int **d;
	int a, b;

	if (width <= 0 || height <= 0)
		return (NULL);

	d = malloc(sizeof(int *) * height);

	if (d == NULL)
		return (NULL);

	for (a = 0; a < height; a++)
	{
		d[a] = malloc(sizeof(int) * width);

		if (d[a] == NULL)
		{
			for (; a >= 0; a--)
				free(d[a]);

			free(d);
			return (NULL);
		}
	}

	for (a = 0; a < height; a++)
	{
		for (b = 0; b < width; b++)
			d[a][b] = 0;
	}

	return (d);
}
