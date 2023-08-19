#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * @...: The arguments to be formatted.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);

				count += write(1, &c, 1);
			}
			else if (*format == 's')
				{
					char *str = va_arg(args, char *);
					int i = 0;

					while (str[i] != '\0')
					{
						count += write(1, &str[i], 1);
						i++;
					}
				}
				else if (*format == '%')
					{
						count += write(1, format, 1);
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
