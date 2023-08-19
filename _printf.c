#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * @...: The arguments to be formatted and printed.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;
	char c;
	char *s;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = (char)va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					while (*s)
					{
						write(1, s, 1);
						s++;
						count++;
					}
					break;
				case '%':
					write(1, &format[i], 1);
					count++;
					break;
				default:
					write(1, &format[i - 1], 1);
					write(1, &format[i], 1);
					count += 2;
					break;
			}
		}
	}

	va_end(args);
	return (count);
}
