#include "main.h"

/**
 * _strtok - Customised verson of strtok function
 * @str: String to tokenize
 * @delim: Delimiter to tokenize string with
 *
 * Return: Tokenized string
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_str;
	const char *delim_ptr;
	char *token;

	if (str)
		last_str = str;
	if (!last_str || !*last_str)
		return (NULL);
	token = last_str;
	delim_ptr = _strchr((char *)delim, *last_str);

	while (delim_ptr == NULL && *last_str != '\0')
	{
		last_str++;
		delim_ptr = _strchr((char *)delim, *last_str);
	}
	if (*last_str != '\0')
	{
		*last_str = '\0';
		last_str++;
	}
	return (token);
}

/**
 * _strdup - Customized version of strdup function
 * @str: String to duplicate
 *
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	size_t len = _strlen(str) + 1;
	char *dup = malloc(len);

	if (!dup)
		return (NULL);
	return (_memcpy(dup, str, len));
}

/**
 * _strchr - Locates the first occurence of a character in a string
 * @s: The string to search
 * @c: The character to locate
 *
 * Return: A pointer to the first coccurrence of c in s, or NULL not found.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

/**
 * _strcmp - Compares two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 *
 * Return: 0, <0 or >0.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

