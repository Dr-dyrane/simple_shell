#include "main.h"

/**
 * _sbrk - customised sbrk
 *
 * @increment: the number of bytes to increase the program break by
 *
 * Return: a pointer to the start of the newly allocated memory block
 */
void *_sbrk(ptrdiff_t increment)
{
	static char *memory_pool;
	static char *program_break;
	void *allocated_memory = NULL;

	if (memory_pool == NULL)
	{
		memory_pool = malloc(MEMORY_POOL_SIZE);
		if (memory_pool == NULL)
			return (NULL);
		program_break = memory_pool;
	}

	if (program_break + increment >= memory_pool + MEMORY_POOL_SIZE)
		return (NULL);

	allocated_memory = program_break;
	program_break += increment;
	return (allocated_memory);
}

