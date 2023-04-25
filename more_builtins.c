#include "main.h"

/**
 * unsetenv_builtin - Unsets an enviroment variable
 * @args: Array of arguments
 * @envp: Array of enviromental variables
 *
 * Return: Always returns 0 to continue execution.
 */
int unsetenv_builtin(char **args, char **envp __attribute__((unused)))
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
	}
	else
	{
		if (unsetenv(args[1]) != 0)
		{
			perror("unsetenv");
		}
	}
	return (0);
}
/* Declare the array of builtins */
builtin _builtin[] = {
	{"cd", cd},
	{"help", help},
	{"exit", exit_shell},
	{"env", env},
	{"setenv", setenv_builtin},
	{"unsetenv", unsetenv_builtin},
	{"ls", ls},
	{NULL, NULL}
};

/**
 * ls - list files in directory
 * @args: arguments passed to the function
 * @envp: environment variables
 *
 * Return: Always 0.
 */
int ls(char **args, char **envp __attribute__((unused)))
{
	DIR *dir;
	struct dirent *entry;
	int len = 0;
	char *space = " ";
	int include_hidden = 0;

    /* Check if the first argument is the "-a" flag */
	if (args[1] != NULL && strcmp(args[1], "-a") == 0)
	{
		include_hidden = 1;
	}
	if (args[1] == NULL)
	{
		dir = opendir(".");
	}
	else
	{
		dir = opendir(args[1]);
	}
	if (dir == NULL)
	{
		perror("opendir");
		return (0);
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (include_hidden || entry->d_name[0] != '.')
		{
			len = _strlen(entry->d_name);
			write(STDOUT_FILENO, entry->d_name, len);
			write(STDOUT_FILENO, space, 1);
			/* write(STDOUT_FILENO, "\n", 1); */
		}
	}
	_putchar('\n');

	closedir(dir);
	return (0);
}
