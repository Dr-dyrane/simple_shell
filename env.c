#include "main.h"

/**
 * env_to_array - Converts enviroment variables to an array
 *
 * Return: Array of enviroment variables
 */
char **env_to_array(void)
{
	int count = 0;
	char **p = environ;

	while (*p != NULL)
	{
		count++;
		p++;
	}

	char **envp = malloc((count + 1) * sizeof(char *));

	if (envp == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	p = environ;
	int i = 0;

	while (*p != NULL)
	{
		envp[i] = *p;
		i++;
		p++;
	}
	envp[i] = NULL;

	return (envp);
}

