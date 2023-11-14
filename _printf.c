#include "main.h"
/**
 * _printf - produces output according to a format
 * @format:  is a character string
 * Return: the string excluding the null byte.
 */

int _printf(const char *format, ...)
{
	int chara_print;
	va_list list_of_args;

	chara_print = 0;

	if (format == NULL)
		return (-1);

	va_start(list_of_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chara_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				chara_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_of_args, int);

				write(1, &c, 1);
				chara_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_of_args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				chara_print += str_len;
			}
		}
		format++;
	}
	va_end(list_of_args);

	return (chara_print);
}
/**
 * _strlen - returns length of a string
 * @s : the string
 * Return: string len
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

