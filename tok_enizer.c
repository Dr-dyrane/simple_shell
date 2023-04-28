#include "main.h"

/**
 * tokenizer - tokenizes any string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **tok_enizer(char *str)
{
	char **tokens;
	char *token;
	unsigned int au;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		report_errors(3);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n\t\r ");

	au = 0;
	while (token != NULL)
	{
		tokens[au] = token;
		token = strtok(NULL, "\n\t\r ");
		au++;
	}

	tokens[au] = NULL;

	return (tokens);
}
