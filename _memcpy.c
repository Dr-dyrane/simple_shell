#include "main.h"

/**
 * _memcpy - custom implementation of memcpy
 *
 * @dest: a ponter to teh destination memory block
 * @src: a pointer to the source memory block
 * @n: the number of bytes to copy
 *
 * Return: a pointer to the destination memory block
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;

	while (n--)
		*d++ = *s++;

	return (dest);
}


