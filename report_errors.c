#include "main.h"

/**
 * report_errors - prints errors based on case
 * @error: error number associated with perror statement
 * Return: void
 */
void report_errors(int error)
{
	switch (error)
	{
	case 1: /* to writes fork error to stderr */
		write(STDERR_FILENO, ERR_FORK, _strlen(ERR_FORK));
		perror("Error");
		break;

	case 2: /* to writes execve error to stderr */
		perror("Error");
		break;

	case 3: /* to writes malloc error to stderr */
		write(STDERR_FILENO, ERR_MALLOC, _strlen(ERR_MALLOC));
		break;
	case 4: /* to writes empty path error to stderr */
		write(STDERR_FILENO, ERR_PATH, _strlen(ERR_PATH));
		break;

	default:
		return;
	}
}
