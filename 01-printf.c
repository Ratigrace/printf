#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 *
 * @format: is a character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    int printed_chars = 0;

    while (*format) {
        if (*format != '%') {
            _putchar(*format);
            printed_chars++;
        } else {
            format++;

            // Handle format specifiers
            switch (*format) {
                case 'c':
                    count = _putchar((char) va_arg(args, int));
                    break;
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str) {
                        count = _putchar(*str++);
                        printed_chars++;
                    }
                    count = 0;  // Reset count since it's not used for calculating printed_chars
                    break;
                }
                case 'd':
                case 'i':
                    // Handle integer formatting
                    /* ... */
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

