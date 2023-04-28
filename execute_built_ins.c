#include "main.h"
/**
**execute_built_ins - to executes the built in functions
**@tokens: arguments being passed
**Return: tokens
**/
int execute_built_ins(char **to_kens)
{

	unsigned int le_ngth;
	int position;
	unsigned int numba;
	unsigned int ua;

	built_s builtin[] = {
		{"exit", my_shell_exit},
		{"env", my_shell_env},
		{NULL, NULL}
	};

	if (to_kens[0] == NULL)
		return (1);

	le_ngth = _strlen(to_kens[0]);

	numba = shell_num_builtins(builtin);
	for (ua = 0; ua < numba; ua++)
	{
		if (_strcmp(to_kens[0], builtin[ua].name, le_ngth) == 0)
		{
			position = (builtin[ua].p)();
			return (position);
		}
	}
	return (1);
}

/**
**shell_num_builtins - this check numba built-ins
**@builtin: takes the builtin to be counted
**Return: numba of builtins
**/

int shell_num_builtins(built_s builtin[])
{
	unsigned int ua;

	ua = 0;
	while (builtin[ua].name != NULL)
		ua++;

	return (ua);
}
