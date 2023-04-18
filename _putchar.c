#include "main.h"

/**
 * _putchar - writes a character to the standard output
 *
 * @c: the character to write
 *
 * Return: on success, the character written; on error, -1
 */
int _putchar(int c)
{
	char character = (char) c;
	ssize_t result = write(STDOUT_FILENO, &character, 1);

	if (result == -1)
	{
		return (-1);
	}
	else
	{
		return (c);
	}
}

