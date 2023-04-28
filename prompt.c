#include "main.h"

/**
 * prompt - to checks for mode and prints prompt if in interactive mode
 * @fd: file stream
 * @buf: the buffer
**/
void prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);
}

/**
 * _puts - prints a string without a \n
 * @str: string to print
 * Return: return void
 */
void _puts(char *str)
{
	unsigned int len1;

	len1 = _strlen(str);

	write(STDOUT_FILENO, str, len1);
}
