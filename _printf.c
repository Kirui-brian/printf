#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: Format string containing conversion specifiers.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format ...)
{
	va_list args;
	int count = 0;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;

			switch (*format)
			{
				case 'c':
					count += write(1, va_args(args, int), 1);
					break;
				case 's':
					str = va_args(args, char *);
					if (str == NULL)
						str = "(NULL)";
					count += write(1, str, _strlen(str));
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%", 1);
					count += write(1, format, 1);
					break;
			}
		}
		else
		{
			count += write(1, format, 1);
		}

		format++;
	}

	va_end(args);

	return (count);
}

/**
 * _strlen - Custom strlen function.
 * @s: String.
 *
 * Return: Length of the string.
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
