#include "main.h"

/**
 * main - main function for the simple shell program
 *
 * Return: always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int status;
	char **envp = env_to_array();

	while (1)
	{
		print_prompt();

		nread = _getline(&line, &len, stdin);

		if (nread == EOF || (_strcmp(line, "exit\n") == 0))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		status = execute(line, envp);

		free(line);
		line = NULL;

		if (status == EXIT_FAILURE)
			exit(EXIT_FAILURE);
	}

	return (0);
}

