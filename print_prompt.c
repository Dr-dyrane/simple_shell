#include "main.h"

/**
 * print_prompt - Prints the prompt
 *
 * Return: void
 */
void print_prompt(void)
{
	char *prompt = "(sh)$ ";
	size_t len = _strlen(prompt);

	if (write(STDOUT_FILENO, prompt, len) == -1)
		perror("write");
}
