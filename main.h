#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _print_unsigned(unsigned int n);
int _print_octal(unsigned int n);
int _print_hex(unsigned int n, int uppercase);
int _handle_conversion(char specifier, va_list args);
int _print_binary(unsigned int n);
int _print_number(int n);
int _puts(char *str);
int _putchar(char c);
int _printf(const char *format, ...);

#endif

