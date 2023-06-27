#include "main.h"

/**
 * _strrev - reverses a string
 *
 * @str: the string to be reversed
 */

void _strrev(char *str)
{
	int i = 0, j = _strlen(str) - 1;
	char temp;

	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
