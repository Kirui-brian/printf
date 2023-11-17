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
	unsigned int j = 0, length = 0, jbuff =0;
	int(*func)(va_list, char *, unsigned int);
	char buff;

	va_start(args, format), buff = malloc(sizeof(char) * 1024);
	if (!format || !buff || (format[j] == '%' && !format[j + 1]))
		return (-1);
	if (!format[j])
		return (0);
	for (j = 0; format && format[j]; j++)
	{
		if (format[j] == '%')
		{
			if (format[j + 1] =='\0')
			{
				print_buff(buff, jbuff), free(buff), va_end(args);
				return (-1);
			}
			else
			{
				func = chuk_print_func(format, j + 1);
				if (func == NULL)
				{
					if (format[j + 1] == ' ' && !format[j + 2])
						return (-1);
					buff_handler(buff, format[j], jbuff), length++, j--;
				}
				else
				{
					length += func(args, buff, jbuff);
					j += we_print_func(format, j + 1);
				}
			}
			j++;
		}
		else
			buff_handler(buff, format[j], jbuff), length++;
		for (jbuff + length; buff > 1024; jbuff -= 1024);
	}
	print_buff(buff, jbuff), free(buff), va_end(args);
	return (length);
}
