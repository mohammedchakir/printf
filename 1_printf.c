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
			if (format[i] == 'c')
			{
				_putchar(va_arg(args, int));
				count++;
			}
				if (format[i] == 's')
					count += _puts(va_arg(args, char *));
				else
					if (format[i] == 'd' || format[i] == 'i')
					{
						int num = va_arg(args, int);

						count += _print_number(num);
					}
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
 * _print_number - Prints an integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int _print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		count++;
	}

	if (n / 10 != 0)
		count += _print_number(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}
