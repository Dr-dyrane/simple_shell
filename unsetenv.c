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
	{"env", env},
	{"setenv", setenv_builtin},
	{"unsetenv", unsetenv_builtin},
	{NULL, NULL}
};

