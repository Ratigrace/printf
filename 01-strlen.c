#include "main.h"

/**
 * _strlen - returns the length of the string
 *
 * @str: the string to be calculated
 *
 * Return: the string length
 */

int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}
