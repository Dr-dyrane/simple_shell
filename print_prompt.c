#include "main.h"

/**
 * print_prompt - Prints the prompt
 *
 * Return: void
 */
void print_prompt(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		for (int i = 0; cwd[i] != '\0'; i++)
			_putchar(cwd[i]);
		_putchar('$');
		_putchar(' ');
	}
	else
		perror("getcwd() error");
}

