#include "main.h"

/**
 * _isdigit - Check if a character is a digit or not
 * @c: The character to be check
 *
 * Return: 1 only if the character is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _atoi - Convert a string to integer
 * @s: The string to be converted
 *
 * Return: integer value of the string
 */
int _atoi(char *s)
{
	int hint = 1;
	int outcom = 0;

	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			hint = -1;
		s++;
	}
	while (_isdigit(*s))
	{
		outcom = outcom * 10 + (*s - '0');
		s++;
	}
	return (hint * outcom);
}

