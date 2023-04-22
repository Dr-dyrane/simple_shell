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

	size_t argc = 0;
	char *copy = _strdup(line);
	char *token = _strtok(copy, " \t\n");

	while (token)
	{
		argc++;
		token = _strtok(NULL, " \t\n");
	} free(copy);

	char **argv = malloc(sizeof(char *) * (argc + 1));

	if (!argv)
	{
		perror("malloc");
		return (EXIT_FAILURE);
	} argc = 0;
	token = _strtok(line, " \t\n");
	while (token)
	{
		argv[argc++] = token;
		token = _strtok(NULL, " \t\n");
	} argv[argc] = NULL; /*Last element should be NULL */
	if (execve(argv[0], argv, envp) == -1)
	{
		perror("execve");
		free(argv);
		return (EXIT_FAILURE);
	} free(argv);
	return (EXIT_SUCCESS);
}

