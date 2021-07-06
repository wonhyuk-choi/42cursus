#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void ft_inter(char *str1, char *str2)
{
	int	check[127];
	int	count;
	char *tmp;

	count = 0;
	while(count < 127)
		check[count++] = 0;
	while (*str2)
	{
		check[*str2] = 1;
		str2++;
	}
	while (*str1)
	{
		if (check[*str1] == 1)
			write(1, str1, 1);
		check[*str1] = 0;
		str1++;
	}
}

int main(int argc, char **argv)
{
	if (argc ==3)
		ft_inter(*(argv + 1), *(argv + 2));
	write(1, "\n", 1);
	return (0);
}