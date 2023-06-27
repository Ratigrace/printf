#include "main.h"

/**
 * print_string - Prints a string
 *
 * @arg_type: the va_list containing the arguments
 * @buffer: the character buffer (unused)
 * @flags: the flags for formatting (unused)
 * @width: the width for formatting (unused)
 * @precision: the precision for formatting (unused)
 * @size: the size of the buffer (unused)
 *
 * Return: the number of characters written.
 */

int print_string(va_list arg_type, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = 0, i;
        char *str;

	str = va_arg(arg_type, char *);

	UNUSED(size);
	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(width);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
	{
		len++;
	}

	if (precision >= 0 && precision < len)
	{
		len = precision;
	}

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = (width - len); i > 0; )
			{
				write(1, " ", 1);
				return (width);
				i--;
			}
			else
			{
				for (i = (width - len); i > 0; )
				{
					write(1, " ", 1);
					i--;
				}

				write(1, &str[0], len);
				return (width);
			}
		}
		write(1, str, len);

		return (0);
}

/**
 * print_char - Prints a character
 *
 * @arg_type: the va_list containing the arguments
 * @buffer: the character buffer to store the output
 * @flags: the flags for formatting
 * @width: the width for formatting
 * @precision: the precision for formatting
 * @size: the size of the buffer
 *
 * Return: the number of characters written
 */
int print_char(va_list arg_type, char buffer[], int flags, int width,
		int precision, int size)
{
	char ch;
	
	ch = va_arg(arg_type, int);

	handle_write_char(ch, buffer, flags, width, precision, size);

	return (0);
}

/**
 * print_percent - Prints a percent symbol
 *
 * @arg_type: the va_list containing the arguments (unused)
 * @buffer: the character buffer (unused)
 * @flags: the flags for formatting (unused)
 * @width: the width for formatting (unused)
 * @precision: the precision for formatting (unused)
 * @size: the size of the buffer (unused)
 *
 * Return: the number of characters written.
 */

int print_percent(va_list arg_type, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(arg_type);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(flags);
	
	return (write(1, "%%", 1));

	return (0);
}
