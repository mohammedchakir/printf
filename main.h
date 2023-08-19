#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Macros flag modifier */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Macros lenght modifier */
#define SHORT 1
#define LONG 2

/**
 * struct s_buffer - A new type defining a buffer struct
 * @buffer: A pointer to a character array
 * @start: A pointer to the start of buffer
 * @len: The length of string stored in buffer
 */
typedef struct s_buffer
{
	char *buffer;
	char *start;
	unsigned int len;
} t_buffer;

/**
 * struct s_converter - A new type defining a converter struct
 * @specifier: A character representing a conversion specifier
 * @func: A pointer to a conversion function corresponding to specifier
 */
typedef struct s_converter
{
	unsigned char specifier;
	unsigned int (*func)(va_list, t_buffer *,
			unsigned char, int, int, unsigned char);
} t_converter;

/**
 * struct s_flag - A new type defining a flags struct
 * @flag: A character representing a flag
 * @value: The integer value of the flag
 */
typedef struct s_flag
{
	unsigned char flag;
	unsigned char value;
} t_flag;

int _printf(const char *format, ...);

/* Functions conversion specifier */
unsigned int c_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int s_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int di_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int percent_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int b_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int u_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int o_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int x_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int X_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int S_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int p_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int r_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int R_convert(va_list args, t_buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/* Handlers */
unsigned char h_flags(const char *flags, char *index);
unsigned char h_length(const char *modifier, char *index);
int h_width(va_list args, const char *modifier, char *index);
int h_precision(va_list args, const char *modifier, char *index);
unsigned int (*h_specifiers(const char *specifier))(va_list, t_buffer *,
		unsigned char, int, int, unsigned char);

/* Modifiers */
unsigned int p_width(t_buffer *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int p_string_width(t_buffer *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int p_neg_width(t_buffer *output, unsigned int printed,
		unsigned char flags, int wid);

/* Helper Functions */
t_buffer *init_buffer(void);
void f_buffer(t_buffer *output);
unsigned int p_memcpy(t_buffer *output, const char *src, unsigned int n);
unsigned int sbase_convert(t_buffer *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int ubase_convert(t_buffer *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);

#endif
