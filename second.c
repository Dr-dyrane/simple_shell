#include "main.h"

/**
 * second - function for second process
 * @wholepath: whole path of executable
 * @tokens: tokenized user input
 * Return: always 0
 */

int second(char *wholepath, char **to_kens)
{
	pid_t second_pid;
	int position;
	int execve_position;
	char **envp = environ;

	second_pid = fork();
	if (second_pid == -1)
	{
		report_errors(1);
		exit(EXIT_FAILURE);
	}
	if (second_pid == 0)
	{
		execve_position = execve(wholepath, to_kens, envp);
		if (execve_position == -1)
			return (-1);
	}
	else
		wait(&position);

	return (0);
}
