#include "main.h"

/**
 * print_prompt - Prints the prompt for us
 *
 * Return: void to be returned
 */
void print_prompt(void)
{
	char cwd[1024];
	int au_i;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		for (au_i = 0; cwd[au_i] != '\0'; au_i++)
			_putchar(cwd[au_i]);
		_putchar('$');
		_putchar(' ');
	}
	else
		perror("getcwd() error");
}

