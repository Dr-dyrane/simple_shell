#include "main.h"

/**
 * execute - Executes a command
 * @line: command to execute
 * @envp: enviroment variables array
 *
 * Return: EXIT_SUCCESS on success, EXIT-FAILURE on failure
 */
int execute(char *line, char **envp)
{
	size_t len = _strlen(line);

	if (len == 0)
		return (EXIT_SUCCESS);
	if (line[len - 1] != '\n')
	{
		line[len - 1] = '\n';
		len--;
	}
	write(STDOUT_FILENO, line, len);

	char *argv[1024];
	size_t argc = parse_args(line, argv);
	int i, status;

	for (i = 0; argv[i] != NULL; i++)
	{
		for (int j = 0; my_builtins[j].name != NULL; j++)
		{
			if (_strcmp(argv[i], my_builtins[j].name) == 0)
			{
				status = my_builtins[j].func(argv, envp);
				goto free_argv;
			}
		}
	}
	status = execute_command(argv, envp);
free_argv:
	for (int i = 0; i < argc; i++)
	{
		free(argv[i]);
	}
	return (status);
}

/**
 * parse_args - Parses arguments from a command line
 * @line: Command line to parse
 * @argv: Array to store parsed arguments
 *
 * Return: Number of arguments parsed
 */
size_t parse_args(char *line, char **argv)
{
	size_t argc = 0;
	char *token = _strtok(line, " \t\n");

	while (token)
	{
		argv[argc] = _strdup(token);
		if (!argv[argc])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		argc++;
		token = _strtok(NULL, " \t\n");
	}
	argv[argc] = NULL; /*Last element should be NULL */
	return (argc);
}

/**
 * execute_command - Executed a command with a given arguments
 * @argv: Array of arguments for the command
 * @envp: Array of enviroment variables
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int execute_command(char **argv, char **envp)
{
	if (execve(argv[0], argv, envp) == -1)
	{
		perror("execve");
	}
	return (EXIT_SUCCESS);
}

