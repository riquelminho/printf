#include <stdio.h>
#include <stdarg.h>
#include "main.h"



/**
* _printf - print output according to a format
* @format: format string
*
* Return: number of characters printed
*/

int _printf(const char *format, ...)
{
va_list arg_list;
int count = 0;

va_start(arg_list, format);

while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
int c = va_arg(arg_list, int);
putchar(c);
count++;
}
else if (*format == 's')
{
char *s = va_arg(arg_list, char *);
while (*s)
{
putchar(*s);
s++;
count++;
}
}
else if (*format == '%')
{
putchar('%');
count++;
}
}
else
{
putchar(*format);
count++;
}
format++;
}

va_end(arg_list);

return (count);
}
