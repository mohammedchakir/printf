# *0x11. C - printf*

 By: Julien Barbier, co-founder & CEO

## Concepts:

For this project, we expect you to look at these concepts:

- [Group Projects](https://intranet.alxswe.com/concepts/111)
- [Pair Programming - How To](https://intranet.alxswe.com/concepts/121)
- [Flowcharts](https://intranet.alxswe.com/concepts/130)
- [Technical Writing](https://intranet.alxswe.com/concepts/225)

## Background Context:

![Write your own printf function](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/228/printf.png)

## Resources:

- [Secrets of printf](https://www.academia.edu/10297206/Secrets_of_printf_)
- Group Projects concept page (Don’t forget to read this)
- Flowcharts concept page

## GitHub:

There should be one project repository per group. The other members do not fork or clone the project to ensure only one of the team has the repository in their github account otherwise you risk scoring 0%

## Authorized functions and macros:

   - `write (man 2 write)`
   - `malloc (man 3 malloc)`
   - `free (man 3 free)`
   - `va_start (man 3 va_start)`
   - `va_end (man 3 va_end)`
   - `va_copy (man 3 va_copy)`
   - `va_arg (man 3 va_arg)`

## Compilation:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

## TASKS:

#### [0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life](0_printf.c)

Write a function that produces output according to a format.

- Prototype: int _printf(const char *format, ...);
- Returns: the number of characters printed (excluding the null byte used to end output to strings)
- write output to stdout, the standard output stream
- format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
   - c
   - s
   - %
- You don’t have to reproduce the buffer handling of the C library printf function
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

#### [1. Education is when you read the fine print. Experience is what you get if you don't](1_functions.c)

Handle the following conversion specifiers:

- d
- i
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

#### [2. With a face like mine, I do better in print](2_functions.c)

Handle the following custom conversion specifiers:

- b: the unsigned int argument is converted to binary

#### [3. What one has not experienced, one will never understand in print](3_functions.c)

Handle the following conversion specifiers:

- u
- o
- x
- X
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

#### [4. Nothing in fine print is ever good news](4_get_flags.c)

- Use a local buffer of 1024 chars in order to call write as little as possible

#### [5. My weakness is wearing too much leopard print](5_get_size.c)

Handle the following custom conversion specifier:

- S : prints the string.
- Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)

#### [6. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print](6_get_precision.c)

Handle the following conversion specifier: p.

- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

#### [7. The big print gives and the small print takes away](7_get_width.c)

Handle the following flag characters for non-custom conversion specifiers:
- `+`
- `space`
- `#`

#### [8. Sarcasm is lost in print](8_handle_print.c)

Handle the following length modifiers for non-custom conversion specifiers:

- l
- h
- Conversion specifiers to handle: d, i, u, o, x, X

#### [9. Print some money and give it to us for the rain forests](9_utils.c)

Handle the field width for non-custom conversion specifiers.

#### [10. The negative is the equivalent of the composer's score, and the print the performance](10_write_handlers.c)

Handle the precision for non-custom conversion specifiers.

#### [11. It's depressing when you're still around and your albums are out of print]()

Handle the 0 flag character for non-custom conversion specifiers.

#### [12. Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection]()

Handle the - flag character for non-custom conversion specifiers.

#### [13. Print is the sharpest and the strongest weapon of our party]()

Handle the following custom conversion specifier:

- r : prints the reversed string

#### [14. The flood of print has turned reading into a process of gulping rather than savoring]()

Handle the following custom conversion specifier:

- R: prints the rot13'ed string

#### [15. *]()

All the above options work well together.








-----------------
## Collaborators:

[OMOTAYO IKUDAYISI](https://github.com/Glitzzybetty) & [MOHAMMED CHAKIR](https://github.com/mohammedchakir)
