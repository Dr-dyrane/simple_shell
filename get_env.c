#include "main.h"

/**
 * get_env - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *get_env(const char *name)
{
	char **environ_dup;
	char *variable, *value, *path;
	int compare;
	unsigned int path_length, environ_length, length, au;

	environ_length = 0;
	while (environ[environ_length] != NULL)
		environ_length++;
	environ_dup = NULL;
	environ_dup = dup_env(environ_dup, environ_length);

	length = _strlen((char *)name);
	au = 0;
	while (environ_dup[au] != NULL)
	{
		variable = environ_dup[au];
		compare = _strncmp((char *)name, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			if (value == NULL)
			{
				report_errors(4);
				exit(EXIT_FAILURE);
			}
			path_length = _strlen(value);
			path = malloc(sizeof(char) * path_length + 1);
			if (path == NULL)
			{
				report_errors(3);
				return (NULL);
			}
			path = _strcpy(path, value);
			free_dp(environ_dup, environ_length);
			return (path);
		}
		au++;
	}
	return (NULL);
}

/**
 * dup_env - copies environment variable
 * @environ_dup: pointer to copy of environment variable
 * @env_le_ngth: length of environment variable
 * Return: double pointer to copy of environment variable
 */
char **dup_env(char **environ_dup, unsigned int env_le_ngth)
{
	char *variable;
	unsigned int variable_length;
	unsigned int au;

	environ_dup = malloc(sizeof(char **) * (env_le_ngth));
	if (environ_dup == NULL)
	{
		report_errors(3);
	
		return (NULL);
	}

	au = 0;
	while (au < env_le_ngth)
	{
		variable = environ[au];
		variable_length = _strlen(variable);

		environ_dup[au] = malloc(sizeof(char) * variable_length + 1);
		if (environ_dup[au] == NULL)
		{
			report_errors(3);
			return (NULL);
		}
		_strcpy(environ_dup[au], environ[au]);
		au++;
	}

	return (environ_dup);
}
