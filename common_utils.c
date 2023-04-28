#include "main.h"

/**
 * _strcmp - compares two strings to find out if they are exactly the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length of name
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strcmp(char *name, char *variable, unsigned int length)
{
	unsigned int variable_length;
	unsigned int au;

	variable_length = _strlen(variable);
	if (variable_length != length)
		return (-1);

	au = 0;
	while (name[au] != '\0' && variable[au] != '\0')
	{
		if (name[au] != variable[au])
			return (1);
		au++;
	}
	return (0);
}

/**
 * _strncmp - compares two strings
 * up to given length are the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *name, char *variable, unsigned int length)
{
	unsigned int au;

	au = 0;
	while (au < length)
	{
		if (name[au] != variable[au])
			return (-1);
		au++;
	}
	return (1);
}

/**
 * *_strcpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: string source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int au_i;
	int au_j = _strlen(src);

	for (au_i = 0; au_i <= au_j; au_i++)
		dest[au_i] = src[au_i];

	return (dest);
}
/**
 * _strlen - returns the length of a string
 * @s: string to be evaluated
 * Return: length of string
 */
int _strlen(char *s)
{
	int au_i = 0;

	while (s[au_i] != '\0')
		au_i++;

	return (au_i);
}
