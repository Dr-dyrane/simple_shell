#include "main.h"

/**
 * _directpath - it searches the directories in the PATH variables for command
 * @order: to search for
 * @wholepath: whole path of order to execute
 * @path: full PATH variable
 * Return: pointer to whole_path
 */
char *_directpath(char *order, char *wholepath, char *path)
{
	unsigned int comand_le_ngth, path_len_gth, first_path_length;
	char *path_dup, *token;

	comand_le_ngth = _strlen(order);
	first_path_length = _strlen(path);
	path_dup = malloc(sizeof(char) * first_path_length + 1);
	if (path_dup == NULL)
	{
		report_errors(3);
		return (NULL);
	}
	_strcpy(path_dup, path);

	/* copy PATH directory + command name and check if it exists */
	token = strtok(path_dup, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_len_gth = _strlen(token);
		wholepath = malloc(sizeof(char) * (path_len_gth + comand_le_ngth) + 2);
		if (wholepath == NULL)
		{
			report_errors(3);
			return (NULL);
		}
		_strcpy(wholepath, token);
		wholepath[path_len_gth] = '/';
		_strcpy(wholepath + path_len_gth + 1, order);
		wholepath[path_len_gth + comand_le_ngth + 1] = '\0';
		if (access(wholepath, X_OK) != 0)
		{
			free(wholepath);
			wholepath = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path_dup);
	return (wholepath);
}
