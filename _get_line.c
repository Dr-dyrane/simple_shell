#include "main.h"

/**
 * _get_line - puts input from user into buffer line
 * @fp: buffer for user input
 * Return: buffer with user input
 */
char *_get_line(FILE *fp)
{
	char *line;
	ssize_t read_data;
	size_t le_ngth;

	line = NULL;
	le_ngth = 0;
	read_data = getline(&line, &le_ngth, fp);
	if (read_data == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
