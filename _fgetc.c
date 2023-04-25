#include "main.h"

/**
 * _fgetc - get a character from a file stream
 *
 * @stream: pointer to the file stream
 *
 * Return: the character read, or EOF on error
 */
int _fgetc(FILE *stream)
{
	char c;
	int ret;

	ret = read(fileno(stream), &c, 1);

	return (ret == -1 ? EOF : (int)c);
}

