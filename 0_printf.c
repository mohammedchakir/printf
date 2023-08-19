#include "main.h"

void clean_up(va_list args, t_buffer *output);
int execute_printf(const char *format, va_list args, t_buffer *output);
int _printf(const char *format, ...);

/**
 * clean_up - Peforms cleanup operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A t_buffer struct.
 */
void clean_up(va_list args, t_buffer *output)
{
	va_end(args);
	write(1, output->start, output->len);
	f_buffer(output);
}

/**
 * execute_printf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A t_buffer struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int execute_printf(const char *format, va_list args, t_buffer *output)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, t_buffer *, unsigned char, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = h_flags(format + i + 1, &tmp);
			wid = h_width(args, format + i + tmp + 1, &tmp);
			prec = h_precision(args, format + i + tmp + 1,
					&tmp);
			len = h_length(format + i + tmp + 1, &tmp);

			f = h_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += p_memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	clean_up(args, output);
	return (ret);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	t_buffer *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = execute_printf(format, args, output);

	return (ret);
}
