#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 1024

/**
 * print_buffer - Prints the contents of the buffer if it exists
 *
 * @buffer: Array of characters containing the buffered output
 * @buff_ind: Pointer to the index at which to add the next character
 *
 * Return: prints the contents of the buffer and resets the index.
 */

void print_buffer(char buffer[], int *buff_ind);


/**
 * get_width - Extracts the width value from the format specifier
 *
 * @format: Format string
 * @index: Pointer to the current position in the format string
 *
 * Return: The extracted width value
 */

int get_width(const char *format, int *index)
{
    int width = 0;

    while (format[*index] >= '0' && format[*index] <= '9')
    {
        width = width * 10 + (format[*index] - '0');
        (*index)++;
    }

    return width;
}

/**
 * handle_print - Handles the printing of characters based on the format
 *		specifier
 *
 * @format: Format string
 * @index: Pointer to the current position in the format string
 * @list: va_list of arguments
 * @buffer: Array of characters for buffering output
 * @buff_ind: Pointer to the index at which to add the next character
 * @width: Width value for formatting
 *
 * Return: number of characters printed
 */

int handle_print(const char *format, int *index, va_list list, char buffer[], int *buff_ind, int width)
{
    char c;
    char *str;
    int printed_chars = 0, i;

    if (format[*index] == 'c')
    {
        c = (char)va_arg(list, int);
        buffer[*buff_ind] = c;
        (*buff_ind)++;
        if (*buff_ind == BUFF_SIZE)
        {
            print_buffer(buffer, buff_ind);
            printed_chars += BUFF_SIZE;
        }
        (*index)++;
    }
    else if (format[*index] == 's')
    {
        str = va_arg(list, char *);
        i = 0;
        while (str[i] != '\0')
        {
            buffer[*buff_ind] = str[i];
            (*buff_ind)++;
            if (*buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, buff_ind);
                printed_chars += BUFF_SIZE;
            }
            i++;
        }
        (*index)++;
    }
    else if (format[*index] == '%')
    {
        buffer[*buff_ind] = '%';
        (*buff_ind)++;
        if (*buff_ind == BUFF_SIZE)
        {
            print_buffer(buffer, buff_ind);
            printed_chars += BUFF_SIZE;
        }
        (*index)++;
    }
    else
    {
        return -1;
    }
	width++;
    return printed_chars;
}

/**
 * _printf - Produces output according to a format
 *
 * @format: Character string specifying the format
 *
 * Return: The number of characters printed
 *
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	int buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return -1;

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars += buff_ind;
			}
		}
		else
		{
			i++;

			if (format[i] == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_ind);
					printed_chars += buff_ind;
				}
			}
			else
			{
				int width = get_width(format, &i);
				int printed = handle_print(format, &i, list, buffer, &buff_ind, width);
				if (printed == -1)
					return -1;
				printed_chars += printed;
			}
		}
	}

	print_buffer(buffer, &buff_ind);
	printed_chars += buff_ind;

	va_end(list);

	return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}
