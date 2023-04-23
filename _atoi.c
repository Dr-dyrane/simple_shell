#include "main.h"

/**
 * _isdigit - Check if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _atoi - Convert a string to an integer
 * @s: The string to convert
 *
 * Return: The integer value of the string
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;

	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (_isdigit(*s))
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (sign * result);
}

