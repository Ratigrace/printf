#include "main.h"

/**
 * _putstr - writes a string to the standard output
 *
 * @str: the string to be written
 *
 * Return: the number of characters written
 */

int _putstr(const char *str)
{
	int len = _strlen(str);
	int i;

	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
	}
	return (len);
}
