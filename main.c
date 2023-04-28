#include "main.h"
/**
 * main - main loop of shell
 * Return: 0 on success
 */
int main(void)
{
	char *line, *path, *wholepath;
	char **to_kens;
	int flag, builtin_position, second_position;
	struct stat buf;

	while (1)
	{
		prompt(STDIN_FILENO, buf);
		line = _get_line(stdin);
		if (_strcmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		to_kens = tok_enizer(line);
		if (to_kens[0] == NULL)
			continue;
		builtin_position = execute_built_ins(to_kens);
		if (builtin_position == 0 || builtin_position == -1)
		{
			free(to_kens);
			free(line);
		}
		if (builtin_position == 0)
			continue;
		if (builtin_position == -1)
			_exit(EXIT_SUCCESS);
		flag = 0; /* 0 if wholepath is not mallocd */
		path = get_env("PATH");
		wholepath = _directpath(to_kens[0], wholepath, path);
		if (wholepath == NULL)
			wholepath = to_kens[0];
		else
			flag = 1; /* if wholepath was malloc, flag to free */
		second_position = second(wholepath, to_kens);
		if (second_position == -1)
			report_errors(2);
		free_all(to_kens, path, line, wholepath, flag);
	}
	return (0);
}
