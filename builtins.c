#include "main.h"
/**
**my_shell_exit - to exits the shell
**Return: void
**/

int my_shell_exit(void)
{
	return (-1);

}


/**
**my_shell_env - to prints environment
**Return: yes void
**/

int my_shell_env(void)
{
	unsigned int ua;

	ua = 0;
	while (environ[ua] != NULL)
	{
		write(STDOUT_FILENO, environ[ua], _strlen(environ[ua]));
		write(STDOUT_FILENO, "\n", 1);
		ua++;
	}
	return (0);
}
