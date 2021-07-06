#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void ft_union(char *str1, char *str2)
{
	int check[127];
	int count;
	char *tmp;

	count = 0;
	while (count < 127)
		check[count++] = 0;
	tmp = str1;
	while (*tmp)
	{
		check[*tmp] = 1;
		tmp++;
	}
	tmp = str2;
	while (*tmp)
	{
		check[*tmp] = 1;
		tmp++;
	}
	while (*str1)
	{
		if (check[*str1] == 1)
			write(1, str1, 1);
		check[*str1] = 0;
		str1++;
	}
	while (*str2)
	{
		if (check[*str2] == 1)
			write(1, str2, 1);
		check[*str2] = 0;
		str2++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(*(argv + 1), *(argv + 2));
	write(1, "\n", 1);
	return (0);
}