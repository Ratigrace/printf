#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 *
 * @format: is a character string
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0, number_of_chars = 0;
	va_list list_arg;

	va_start(list_arg, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			number_of_chars++;
		}
		else
		{
			format++;
			switch (*format)
			{
			case 'c':
				count = printf("%c", va_arg(list_arg, int));
				break;
			case 's':
				count = printf("%s", va_arg(list_arg, char *));
				break;
			case 'd':
			case 'i':
				count = printf("%d", va_arg(list_arg, int));
				break;
			default:
				_putchar('%');
				_putchar(*format);
				count = 2;
				break;
			}
			number_of_chars += count;
		}
		format++;
	}
	va_end(list_arg);
	return (number_of_chars);
}
