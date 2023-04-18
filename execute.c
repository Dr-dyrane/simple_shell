#include "main.h"

/**
 * execute - Executes a command
 * @line: command to execute
 * @envp: enviroment variables array
 *
 * Return: EXIT_SUCCESS on success, EXIT-failure on failure
 */
int execute(char *line, char **envp)
{
	size_t len = _strlen(line);
	char *args[] = {line, NULL};

	if (line[len - 1] != '\n')
	{
		line[len - 1] = '\n';
		len--;
	}

	if (write(STDOUT_FILENO, line, len) == EOF)
	{
		perror("write");
		return (EXIT_FAILURE);
	}

	if (execve(line, args, envp) == -1)
	{
		perror("execve");
		/*return (EXIT_FAILURE);*/
	}

	return (EXIT_SUCCESS);
}

