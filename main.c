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

	while (1)
	{
		print_prompt();

		nread = _getline(&line, &len, stdin);

		if (nread == -1)
		{
			free(line);
			_putchar('\n');
			exit(EXIT_SUCCESS);
		}

		status = execute(line);

		free(line);
		line = NULL;

		if (status == EXIT_failure)
			exit(EXIT_FAILURE);
	}

	return (0);
}
