#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
*/
int get_precision(const char *format, int *i, va_list list)
{
	int d = 0;

	if (*format != '.')
		return (format);
	format++;
	if (*format == '*')
	{
		d = va_arg(ap, int);
		format++;
	}
	else
	{
		while (_isdigit(*format))
			d = d * 10 + (*format++ - '0');
	}
	format->precision = d;
	return (format);
}
