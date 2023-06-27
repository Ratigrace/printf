#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 *
 * @format: is a character string
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

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
			switch (*format) {
			case 'c': {
				char c = (char) va_arg(args, int);
				_putchar(c);
				printed_chars++;
				break;
			}
			case 's': {
				char *str = va_arg(args, char *);
				printed_chars += _putstr(str);
				break;
			}
			case 'd':
			case 'i': {
				int n = va_arg(args, int);
				printed_chars += _putint(n);
				break;
			}
			case 'x': {
				unsigned int x = va_arg(args, unsigned int);
				char hex_digits[] = "0123456789abcdef";
				char hex[9] = {'\0'};
				int i = 0;
				while (x) {
					hex[i++] = hex_digits[x % 16];
					x /= 16;
				}
				_putstr("0x");
				_putstr(hex);
				printed_chars += 10;  /* including "0x" */
				break;
			}
			case 'p': {
				void *ptr = va_arg(args, void *);
				unsigned long int address = (unsigned long int) ptr;
				char hex_digits[] = "0123456789abcdef";
				char hex[17] = {'\0'};
				int i = 0;
				while (address) {
					hex[i++] = hex_digits[address % 16];
					address /= 16;
				}
				_putstr("0x");
				_putstr(hex);
				printed_chars += 18;  /* including "0x" */
				break;
			}
			default:
				_putchar('%');
				_putchar(*format);
				printed_chars += 2;
				break;
			}
		}

		format++;
	}

	va_end(args);
	return (printed_chars);
}

