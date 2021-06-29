#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static void	print_xnum(unsigned int num)
{
	char	tmp;

	if (num / 16)
		print_xnum(num / 16);
	num %= 16;
	tmp = "0123456789abcdef" [num];
	write(1, &tmp, 1);
}

static int	check_len_x(unsigned int num, int count)
{
	if (num / 16)
		count = check_len_x(num / 16, ++count);
	return (count);
}

static int	x_printf(int first, int second, unsigned int num)
{
	int	len;
	int	zero;
	int	ret;

	len = check_len_x(num, 1);
	zero = 0;
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
	char	tmp;

	if (num / 10)
		print_num(num / 10);
	num %= 10;
	if (num < 0)
		num *= -1;
	tmp = num + 48;
	write(1, &tmp, 1);
}

static int	check_len(int num, int count)
{
	if (num / 10)
		count = check_len(num / 10, ++count);
	return (count);
}

static int	d_printf(int first, int second, int num)
{
	int	len;
	int	zero;
	int	ret;

	len = check_len(num, 1);
	zero = 0;
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
	if (num < 0)
		write(1, "-", 1);
	while (zero-- > 0)
		write(1, "0", 1);
	print_num(num);
	return (ret);
}

static int	s_printf(int first, int second, char *str)
{
	char	*tmp;
	int		len;
	int		ret;

	len = 0;
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

static void	check_num(char **s, int *second)
{
	*second = 0;
	if (**s == '-')
	{
		*second = -1;
		(*s)++;
		while (**s >= 48 && **s <= 57)
			(*s)++;
	}
	else
	{
		while (**s >= 48 && **s <= 57)
		{
			*second = *second * 10 + **s - 48;
			(*s)++;
		}
	}
}

static int	parse(char *s, va_list ap, int *ret)
{
	int		first;
	int		second;
	char	*start;

	start = s;
	first = 0;
	while (*s >= 48 && *s <= 57)
		first = first * 10 + *s++ - 48;
	second = -1;
	if (*s == '.')
	{
		s++;
		check_num(&s, &second);
	}
	if (!(*s == 's' || *s == 'd' || *s == 'x'))
		return (0);
	if (*s == 's')
		*ret += s_printf(first, second, va_arg(ap, char *));
	else if (*s == 'd')
		*ret += d_printf(first, second, va_arg(ap, int));
	else
		*ret += x_printf(first, second, va_arg(ap, int));
	return (s - start + 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		cnt;
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
			cnt = parse((char *)s, ap, &ret);
			if (!cnt)
			{
				va_end(ap);
				return (-1);
			}
			s += cnt;
		}
		else
		{
			write(1, s++, 1);
		}
	}
	va_end(ap);
	return (ret);
}

int	main(void)
{
	int	num;

	num = ft_printf("10.0s |%10.0s|\n", "Hello");
	printf("%d\n", num);
	num = ft_printf("10.s  |%10.s|\n", "Hello");
	printf("%d\n", num);
	num = ft_printf("10s   |%10s|\n", "Hello");
	printf("%d\n", num);
	num = ft_printf("10.4s |%10.4s|\n", "HEllo");
	printf("%d\n", num);
	num = ft_printf("10.7s |%10.7s|\n", "HEllo");
	printf("%d\n", num);
	num = ft_printf(".7s   |%.7s|\n", "HEllo");
	printf("%d\n", num);
	num = ft_printf(".3s   |%.3s|\n", "HEllo");
	printf("%d\n", num);

	num = ft_printf("d    |%d|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("3d   |%3d|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("7d   |%7d|\n", 1234);
	printf("%d\n", num);
	num = ft_printf(".d   |%.d|\n", 1234);
	printf("%d\n", num);
	num = ft_printf(".3d  |%.3d|\n", 1234);
	printf("%d\n", num);
	num = ft_printf(".6d  |%.6d|\n", 1234);
	printf("%d\n", num);
	num = ft_printf(".6d  |%.6d|\n", -1234);
	printf("%d\n", num);
	num = ft_printf("3.3d |%3.3d|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("3.3d |%3.3d|\n", -1234);
	printf("%d\n", num);
	num = ft_printf("6.3d |%6.3d|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("6.3d |%6.3d|\n", -1234);
	printf("%d\n", num);
	num = ft_printf("3.7d |%3.7d|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("3.7d |%3.7d|\n", -1234);
	printf("%d\n", num);
	num = ft_printf("9.7d |%9.7d|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("9.7d |%9.7d|\n", -1234);
	printf("%d\n", num);

	num = ft_printf("x    |%x|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("3x   |%3x|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("7x   |%7x|\n", 1234);
	printf("%d\n", num);
	num = ft_printf(".x   |%.x|\n", 1234);
	printf("%d\n", num);
	num = ft_printf(".3x  |%.3x|\n", 1234);
	printf("%d\n", num);
	num = ft_printf(".6x  |%.6x|\n", 1234);
	printf("%d\n", num);
	num = ft_printf(".6x  |%.6x|\n", -1234);
	printf("%d\n", num);
	num = ft_printf("3.3x |%3.3x|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("3.3x |%3.3x|\n", -1234);
	printf("%d\n", num);
	num = ft_printf("6.3x |%6.3x|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("6.3x |%6.3x|\n", -1234);
	printf("%d\n", num);
	num = ft_printf("3.7x |%3.7x|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("3.7x |%3.7x|\n", -1234);
	printf("%d\n", num);
	num = ft_printf("9.7x |%9.7x|\n", 1234);
	printf("%d\n", num);
	num = ft_printf("9.7x |%9.7x|\n", -1234);
	printf("%d\n", num);
	num = ft_printf("9.7x |%4.-3d|\n", 10);
	printf("%d\n", num);
	num = ft_printf("9.7x |%4.3d|\n", 10);
	printf("%d\n", num);
	num = printf("9.7x |%4.*d|\n", -3, 10);
	printf("%d\n", num);
	num = printf("9.7x |%4.3d|\n", 10);
	printf("%d\n", num);

	return (0);
}