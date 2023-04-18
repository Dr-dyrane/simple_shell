#include "main.h"

/**
 * _realloc - custom implementation of realloc using _sbrk
 *
 * @ptr: a pointer to the memory block to reallocate
 * @size: the new size of teh memory block
 *
 * Return: a pointer to the reallocated memory block
 */
void *_realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
		return (malloc(size));
	void *new_ptr = _sbrk(size);

	if (new_ptr == (void *) -1)
		return (NULL);
	_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}
