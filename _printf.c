#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && (*format + 1) != '\0')
		{
			format++; /* Move to the character after % */
			switch (*format)
			{
				case 'c':
					count += putchar(va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					count += putchar('%');
					break;
				default:
					count += putchar('%');
					count += putchar(*format);
					break;
			}
		}
		else
		{
			count += putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}
