#include "main.h"

/**
 * execute - Executes a command
 * @line: command to execute
 *
 * Return: EXIT_SUCCESS on success, EXIT-failure on failure
 */
int execute(char *line)
{
	size_t len = _strlen(line);

	if (line[len - 1] != '\n')
	{
		line[len - 1] = '\n';
		len--;
	}

	if (write(STDOUT_FILENO, line, len) == -1)
	{
		perror("write");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

