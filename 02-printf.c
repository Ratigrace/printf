#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 *
 * @format: is a character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...);

/**
 * _strlen - returns the length of a string
 *
 * @str: the string
 *
 * Return: the length of the string
 */
int _strlen(const char *str);

/**
 * _putchar - writes a character to the standard output
 *
 * @c: the character to be written
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c);

/**
 * _putstr - writes a string to the standard output
 *
 * @str: the string to be written
 *
 * Return: the number of characters written
 */
int _putstr(const char *str);

/**
 * _putint - writes an integer to the standard output
 *
 * @n: the integer to be written
 *
 * Return: the number of characters written
 */
int _putint(int n);

/**
 * _strrev - reverses a string
 *
 * @str: the string to be reversed
 */
void _strrev(char *str);

/**
 * _strlen - returns the length of a string
 *
 * @str: the string
 *
 * Return: the length of the string
 */
int _strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

/**
 * _putstr - writes a string to the standard output
 *
 * @str: the string to be written
 *
 * Return: the number of characters written
 */
int _putstr(const char *str) {
    int len = _strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        _putchar(str[i]);
    }
    return len;
}

/**
 * _putint - writes an integer to the standard output
 *
 * @n: the integer to be written
 *
 * Return: the number of characters written
 */
int _putint(int n) {
    int count = 0;
    if (n < 0) {
        _putchar('-');
        count++;
        n = -n;
    }
    if (n / 10) {
        count += _putint(n / 10);
    }
    _putchar('0' + n % 10);
    count++;
    return count;
}

/**
 * _strrev - reverses a string
 *
 * @str: the string to be reversed
 */
void _strrev(char *str) {
    int i = 0, j = _strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

/**
 * _printf - produces output according to a format
 *
 * @format: is a character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...) {
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format) {
        if (*format != '%') {
            _putchar(*format);
            printed_chars++;
        } else {
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
    return printed_chars;
}

