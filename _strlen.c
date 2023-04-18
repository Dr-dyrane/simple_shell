#include "main.h"

/**
 * _strlen - calculates the length of a string
 * @s: string to calculate length of
 *
 * Return: length of the string
 */
size_t _strlen(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
	;

	return (i);
}
