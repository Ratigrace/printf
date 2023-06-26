#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 *
 * @format: is a charecter string
 *
 * Return: 0 always
 */

int _printf(const char *format, ...)
{
	int z, len;
	char ch;
	char *str;

	va_list list_arg;

	va_start(list_arg, format);

	for (z = 0; format[z] != '\0'; z++)
	{
		if (format[z] == '%' && (format[z + 1] == 'c'))
		{
			ch = (char)va_arg(list_arg, int);
			write(1, &ch, 1);
			format += 2;
		}
		if (format[z] == '%' && format[z + 1] == 's')
		{
			str = va_arg(list_arg, char*);
			len = _strlen(str);
			write(1, str, len);
			format += 2;
		}
		if (format[z] == '%' && format[z + 1] == '%')
		{
			write(1, "%", 1);
			format += 2;
		}
		write(1, &format[z], 1);
		}

		va_end(list_arg);
		return (0);
}
