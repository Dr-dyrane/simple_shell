#include "main.h"

/**
 * cd - Changes the current working directory
 * @args: Array of arguments
 * @envp: Array of enviroment variables
 *
 * Return: Always returns 0 to continue execution.
 */
int cd(char **args, char **envp)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "cd: expected argument to \"cd\"n", 31);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
	return (0);
}

/**
 * help - Displays help information for shell builtins
 * @args: Array of arguments
 * @envp: Array of enviroment variables
 *
 * Return: Always returns 0 to continue execution.
 */
int help(char **args, char **envp)
{
	write(STDOUT_FILENO, "These shell buiitns are available:\n", 36);
	write(STDOUT_FILENO, "cd\n", 3);
	write(STDOUT_FILENO, "help\n", 5);
	write(STDOUT_FILENO, "exit\n", 5);
	write(STDOUT_FILENO, "env\n", 4);
	write(STDOUT_FILENO, "setenv\n", 7);
	write(STDOUT_FILENO, "unsetenv\n", 9);
	return (0);
}

/**
 * exit_shell - Exits the shell
 * @args: Array of arguments
 * @envp: Array of enviroment variables
 *
 * Return: Always returns 0 to terminate the shell.
 */
int exit_shell(char **args, char **envp)
{
	int status = EXIT_SUCCESS;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
	}

	exit(status);
}

/**
 * env - Displays the enviroment variables
 * @args: Array of argumnets
 * @envp: Array of enviroment variables
 *
 * Return: Always returns 0 to continue execution.
 */
int env(char **args, char **envp)
{
	char **env;

	for (env = envp; *env != NULL; env++)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * setenv_builtin - Sets an enviroment variable
 * @args: Array of arguments
 * @envp: Array of enviroment variables
 *
 * Return: Always return 0 to continue execution.
 */
int setenv_builtin(char **args, char **envp)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
	}
	else
	{
		if (setenv(args[1], args[2], 1) != 0)
		{
			perror("setenv");
		}
	}
	return (0);
}

