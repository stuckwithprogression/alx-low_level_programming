#include <stdio.h>

int is_palindrome(int num);
/**
 * main - entry point to find palindrome program
 *
 * Return: always 0
 */
int main()
{
	int maxPalindrome = 0;
	int i, j, product;
	FILE *file;

	for (i = 100; i < 1000; ++i)
	{
		for (j = 100; j < 1000; ++j)
		{
			product = i * j;

			if (is_palindrome(product) && product > maxPalindrome)
			{
				maxPalindrome = product;
			}
		}
	}

	file = fopen("102-result", "w");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	fprintf(file, "%d", maxPalindrome);
	fclose(file);

	return (0);
}

/**
 * is_palindrome - A function that checks if list is a palindrome.
 * @num: The number to check.
 * Return: 1 if number is a palindrome, or 0 if not.
 */
int is_palindrome(int num)
{
	int original = num;
	int reversed = 0;

	while (num > 0)
	{
		reversed = reversed * 10 + num % 10;
		num /= 10;
	}

	return (original == reversed);
}
