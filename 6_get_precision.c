#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;
	
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		} else
			if (format[curr_i] == '*') {
				curr_i++;
				precision = va_arg(list, int);
				break;
			}
			else
				break
	}

	*i = curr_i - 1;

	return (precision);
}

int main()
{
	const char *format1 = "%.*s";
	int i1 = 0;
	va_list list1;
	va_start(list1, i1);

	int precision1 = get_precision(format1, &i1, list1);

	printf("Precision: %d\n", precision1);

	va_end(list1);

	const char *format2 = "%.6s";
	int i2 = 0;
	va_list list2;
	va_start(list2, i2);
	
	int precision2 = get_precision(format2, &i2, list2);
	
	printf("Precision: %d\n", precision2);
	
	va_end(list2);
	return 0;
}

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
