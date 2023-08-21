#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @format: the format string
 * @i: pointer to the current index in the format string
 * @list: the argument list
 * Return: new index value
*/
int get_precision(const char *format, int *i, va_list list)
{
	int precision = 0;

	if (format[*i] != '.')
		return (*i);

	(*i)++;

	if (format[*i] == '*')
	{
		precision = va_arg(list, int);
		(*i)++;
	}
	else
	{
		while (_isdigit(format[*i]))
			precision = precision * 10 + (format[(*i)++] - '0');
	}

	return (*i);
}
