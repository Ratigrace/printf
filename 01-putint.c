#include "main.h"

/**
 * _putint - writes an integer to the standard output
 *
 * @n: the integer to be written
 *
 * Return: the number of characters written
 */

int _putint(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
	if (n / 10)
	{
		count += _putint(n / 10);
	}
	_putchar('0' + n % 10);
	count++;
	return (count);
}
