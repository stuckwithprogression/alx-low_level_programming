#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: will be a pointer to a string to write to the file.
 *
 * Return: If function fails return -1.
 *         else - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int opn, wri, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	opn = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wri = write(opn, text_content, len);

	if (opn == -1 || wri == -1)
		return (-1);

	close(opn);

	return (1);
}
