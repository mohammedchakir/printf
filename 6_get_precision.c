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
	int curr_i = *i + 2;
	int precision = -1;

	for (; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else
			break;
	}

	if (format[curr_i] == '*')
	{
		precision = va_arg(list, int);
	}

	*i = curr_i;

	return (precision);
}
