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
	int count = 0;
	int printed_chars = 0;
	va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
	{
            _putchar(*format);
            printed_chars++;
        }
	else
	{
            format++;

            switch (*format)
	    {
                case 'c':
                    count = printf("%c", va_arg(args, int));
                    break;
                case 's':
                    count = printf("%s", va_arg(args, char *));
                    break;
                case 'd':
                case 'i':
                    count = printf("%d", va_arg(args, int));
                    break;
                default:
                    _putchar('%');
                    _putchar(*format);
                    count = 2;
                    break;
            }

            printed_chars += count;
        }

        format++;
    }

    va_end(args);
    return printed_chars;
}
