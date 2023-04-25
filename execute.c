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
	char *argv[1024];
	size_t len = _strlen(line);
	size_t argc = parse_args(line, argv);
	int au_i, au_j, status;
	size_t au;

	if (len == 0)
		return (EXIT_SUCCESS);
	if (line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len--;
	}
	/* write(STDOUT_FILENO, line, len);
	_putchar('\n'); */

	for (au_i = 0; argv[au_i] != NULL; au_i++)
	{
		for (au_j = 0; _builtin[au_j].name != NULL; au_j++)
		{
			if (_strcmp(argv[au_i], _builtin[au_j].name) == 0)
			{
				status = _builtin[au_j].func(argv, envp);
				goto free_argv;
			}
		}
	}
	status = execute_command(argv, envp);
free_argv:
	for (au = 0; au < argc; au++)
	{
		free(argv[au]);
	}
	return (status);
}

/**
 * parse_args - Parses arguments from any command line
 * @line: Command line to be parsed
 * @argv: An array to store parsed arguments
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
	argv[argc] = NULL; /* The Last element here should be NULL */
	return (argc);
}

/**
 * execute_command - Execute commands with a given arguments
 * @argv: An array of arguments for the command
 * @envp: An array of enviroment variables
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
