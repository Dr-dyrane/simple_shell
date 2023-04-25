#include "main.h"

/**
 * _getline - read a line from a file stream
 *
 * @lineptr: pointer to the buffer where the line will be stored
 * @n: The size of the buffer
 * @stream: pointer to the file stream
 *
 * Return: number of characters read, or -1 on error
 */
int _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c, au_i = 0;
	size_t size = *n;

	if (*lineptr == NULL)
	{
		*lineptr = malloc(READ_SIZE);
		if (*lineptr == NULL)
		{
			return (-1);
		}
		size = READ_SIZE;
	}

	while ((c = _fgetc(stream)) != -1)
	{
		if (au_i >= (int)size - 1)
		{
			size += READ_SIZE;
			*lineptr = _realloc(*lineptr, size);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
		(*lineptr)[au_i++] = c;
		if (c == '\n')
		{
			break;
		}
	}

	if (au_i == 0)
	{
		return (-1);
	}

	(*lineptr)[au_i] = '\0';
	*n = size;

	return (au_i);
}
