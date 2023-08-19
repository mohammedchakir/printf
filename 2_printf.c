#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			count += _handle_conversion(format[i], args);
		}
		i++;
	}

	va_end(args);
	return (count);
}

/**
 * _puts - Prints a string followed by a new line
 * @str: The string to print
 *
 * Return: Number of characters printed
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
	return (i + 1);
}

/**
 * _handle_conversion - Handles different conversion specifiers
 * @specifier: The conversion specifier
 * @args: The va_list containing the arguments
 *
 * Return: Number of characters printed
 */
int _handle_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
	{
		_putchar(va_arg(args, int));
		return (1);
	}
	else
		if (specifier == 's')
		{
			return (_puts(va_arg(args, char *)));
		}
		else
			if (specifier == '%')
			{
				_putchar('%');
				return (1);
			}
			else
				if (specifier == 'b')
				{
					return (_print_binary(va_arg(args, unsigned int)));
				}

	return (0);
}

/**
 * _print_binary - Prints an unsigned int in binary
 * @n: The unsigned int to print
 *
 * Return: Number of characters printed
 */
int _print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2 != 0)
		count += _print_binary(n / 2);

	_putchar((n % 2) + '0');
	count++;

	return (count);
}
