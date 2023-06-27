#include "main.h"

/**
 * handle_write_char - Handles writing a single character
 *
 * @c: the character to be written
 * @buffer: the character buffer to store the output
 * @flags: the flags for formatting
 * @width: the width for formatting
 * @precision: the precision for formatting (unused)
 * @size: the size of the buffer (unused)
 *
 * Return: the number of characters written.
 */

int handle_write_char(char ch, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
	{
		padd = '0';
	}

	buffer[i++] = ch;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';

		for (i = 0; i < width - 1; i++)
		{
			buffer[BUFF_SIZE - i - 2] = padd;
		}

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[0], 1) +
			write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		}
		else
		{
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
		}
	}

	return (write(1, &buffer[0], 1));
}
