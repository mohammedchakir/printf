#include "main.h"


/**
 * get_precision - Matches a precision modifier with
 *                    its corresponding value.
 * @format: The format string.
 * @i: A pointer to the current index in the format string.
 * @list: A va_list of arguments.
 *
 * Return: If a precision modifier is matched - its value.
 *         If the precision modifier is empty, zero, or negative - 0.
 *         Otherwise - -1.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int value = 0;

	if (format[*i] != '.')
		return (-1);

	(*i)++;

	if ((format[*i] <= '0' || format[*i] > '9') &&
			format[*i] != '*')
	{
		if (format[*i] == '0')
			(*i)++;
		return (0);
	}

	while ((format[*i] >= '0' && format[*i] <= '9') ||
			(format[*i] == '*'))
	{
		(*i)++;

		if (format[*i] == '*')
		{
			value = va_arg(list, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (format[*i] - '0');
		(*i)++;
	}

	return (value);
}
