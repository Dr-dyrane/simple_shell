#include "main.h"

/**
 * env_to_array - Converts enviroment variables to an array
 *
 * Return: Array of enviroment variables
 */
char **env_to_array(void)
{
	char **envp = NULL;
	int ua_i, count = 0;
	char **ua = environ;

	while (*ua != NULL)
	{
		count++;
		ua++;
	}

	envp = malloc((count + 1) * sizeof(char *));

	if (envp == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	ua = environ;

	while (*ua != NULL)
	{
		envp[ua_i] = _strdup(*ua);
		ua_i++;
		ua++;
	}
	envp[ua_i] = NULL;

	return (envp);
}

