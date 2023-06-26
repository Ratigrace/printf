# 0x11. C - printf

- ** printf.c ** -a  function that produces output according to a format.

		Prototype: int _printf(const char *format, ...);
		Returns: the number of characters printed (excluding the null byte used to end output to strings)
		write output to stdout, the standard output stream
		format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
			c
			s
			%
			i
			d
		don’t have to reproduce the buffer handling of the C library printf function
		don’t have to handle the flag characters
		don’t have to handle field width
		don’t have to handle precision
		don’t have to handle the length modifiers
