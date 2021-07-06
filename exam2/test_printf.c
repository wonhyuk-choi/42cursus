#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

static void print_xnum(unsigned int num)
{
	char tmp;
	
	if (num / 16)
		print_xnum(num / 16);
	num %= 16;
	tmp = "0123456789abcdef"[num];
	write(1, &tmp, 1);
}

static int len_check_x(unsigned int num, int count)
{
	if (num / 16)
		count = len_check_x(num / 16, ++count);
	return (count);
}

static int	x_print(int first, int second, unsigned int num)
{
	int ret;
	int len;
	int zero;

	len = len_check_x(num, 1);
	ret = len;
	if (len < second)
	{
		zero = second - len;
		ret = second;
	}
	if (first > len + zero)
	{
		ret = first;
		while (first-- != len + zero)
			write(1, " ", 1);
	}
	while (zero-- > 0)
		write(1, "0", 1);
	print_xnum(num);
	return (ret);
}

static void	print_num(int num)
{
	char tmp;

	if (num / 10)
		print_num(num / 10);
	num %= 10;
	if (num < 0)
		num *= -1;
	tmp = num + 48;
	write(1, &tmp ,1);
}

static int len_check(int num, int count)
{
	if (num / 10)
		count = len_check(num /10, ++count);
	return (count);
}

static int	d_print(int first, int second, int num)
{
	int ret;
	int len;
	int save_first;
	int zero;

	len = len_check(num, 1);
	save_first = first;
	ret = len;
	if (len < second)
	{
		zero = second - len;
		ret = second;
	}
	if (first > len + zero)
	{
		ret = first;
		if (num < 0)
			first--;
		while (first-- != len + zero)
			write(1, " ", 1);
	}
	else if (first < len + zero && num < 0)
		ret += 1;
	else if (num < 0)
		ret += 1;
	if (num < 0)
		write(1, "-", 1);
	while (zero-- > 0)
		write(1, "0", 1);
	if (save_first != 0 && second == 0)
		write(1, " ", 1);
	else if (second != 0)
		print_num(num);
	else
			ret--;
	return (ret);
}

static int	s_print(int first, int second, char *str)
{
	char *tmp;
	int len;
	int ret;

	len = 0;
	if (str == NULL)
		str = "(null)";
	while (*(str + len))
		len++;
	ret = len;
	if (len > second && second != -1)
	{
		ret = second;
		len = second;
	}
	if (first > len)
	{
		ret = first;
		while (first-- != len)
			write(1, " ", 1);
	}
	while (len-- > 0)
		write(1, str++, 1);
	return (ret);
}

static int	parse(char *s, va_list *ap, int *ret)
{
	int		first;
	int		second;
	char	*start;

	start = s;
	first = 0;
	if (*s == '-')
		s++;
	while (*s >= 48 && *s <= 57)
		first = first * 10 + *s++ - 48;
	second = -1;
	if (*s == '.')
	{
		s++;
		second = 0;
		if (*s == '-')
		{
			second = -1;
			while (*s >= 48 && *s <= 57)
				s++;
		}
		else
		{
			while (*s >= 48 && *s <= 57)
			{
				second = second * 10 + *s - 48;
				s++;
			}
		}
	}
	if (!(*s == 's' || *s == 'd' || *s == 'x'))
		return (0);
	if (*s == 's')
		*ret += s_print(first, second, va_arg(*ap, char *));
	else if (*s == 'd')
		*ret += d_print(first, second, va_arg(*ap, int));
	else
		*ret += x_print(first, second, va_arg(*ap, int));
	return (s - start + 1);
}

int ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		ret;

	ret = 0;
	va_start(ap, s);
	while (*s)
	{
		ret += 1;
		if (*s == '%')
		{
			++s;
			ret -= 1;
			count = parse((char *)s, &ap, &ret);
			if (!count)
			{
				va_end(ap);
				return (-1);
			}
			s += count;
		}
		else
		{
			write(1, s++, 1);
		}
	}
	va_end(ap);
	return (ret);
}