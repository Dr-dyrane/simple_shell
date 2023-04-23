#include "main.h"

/**
 * print_prompt - Prints the prompt
 *
 * Return: void
 */
void print_prompt(void)
{
	char cwd[1024];
	int i;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		for (i = 0; cwd[i] != '\0'; i++)
			_putchar(cwd[i]);
		_putchar('$');
		_putchar(' ');
	}
	else
		perror("getcwd() error");
}

