#include "main.h"

/**
 * get_precision - Calculates the precision
 * @format: Formatted string
 * @i: List of arguments to print
 * @arg_list: list of arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int i_printed = *i + 1;
	int prec = -1;

	if (format[i_printed] != '.')
		return (prec);

	prec = 0;

	for (i_printed += 1; format[i_printed] != '\0'; i_printed++)
	{
		if (_digit(format[i_printed]))
		{
			prec *= 10;
			prec += format[i_printed] - '0';
		}
		else if (format[i_printed] == '*')
		{
			i_printed++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = i_printed - 1;

	return (prec);
}
