#include "main.h"

/**
 * print_c - prints char
 * @list: arguement char
 * Return: pointer args
 */

char *print_c(va_list list)
{
	static char s[2] = {0, '\0'};

	s[0] = va_arg(list, int);
	if (s[0] == '\0')
	{
		return (" ");
	}
	return (s);
}

/**
 * print_s - prints string
 * @list: list to print
 * Return: pointer args
 */

char *print_s(va_list list)
{
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
	{
		return (s = "(null)");
	}
	return (s);
}

/**
 * print_i - Prints an integer
 * @list: list of arguments
 * Return: pointer args
 */

char *print_i(va_list list)
{
	char *output;

	int divisor = 1000000000;
	int digit = 0, i = 0, neg = 0;
	int num = va_arg(list, int);
	int len = _numlen(num);
	output = malloc(len * sizeof(char) + 1 + neg);
	if (output == NULL)
	{
		free(output);
		return (0);
	}
	if (num < 0)
	{
		neg++;
	}
	if (num < 0)
	{
		output[i] = '-';
		i++;
	}
	if (num > -10 && num < 10)
	{
		output[i] = _abs(num) + '0';
		return (output);
	}
	while (divisor)
	{
		digit = (num / divisor) % 10;
		if (num < 0)
		{
			digit = _abs(digit);
		}
		if (digit != 0 || (len >= 0  && output[i - 1] >= '0'))
		{
			output[i] = digit + '0';
			i++;
			len--;
		}
		divisor /= 10;
	}
	output[i] = '\0';
	return (output);
}

/**
 * print_percent - prints a percent
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}



/**
 * print_int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_int(va_list l, flags_t *f)
{
        int n = va_arg(l, int);
        int res = count_digit(n);

        if (f->space == 1 && f->plus == 0 && n >= 0)
                res += _putchar(' ');
        if (f->plus == 1 && n >= 0)
                res += _putchar('+');
        if (n <= 0)
                res++;
        print_number(n);
        return (res);
}

