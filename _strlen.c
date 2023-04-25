#include "main.h"

/**
 * _strlen - calculates the length of a string
 * @s: string to be  calculated of the length
 *
 * Return: length of the string
 */
size_t _strlen(char *s)
{
	size_t au_i;

	for (au_i = 0; s[au_i]; au_i++)
	;

	return (au_i);
}

