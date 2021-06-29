#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_union(char *str1, char *str2)
{
	int		check[127];
	int		count;
	char	*tmp;

	count = 0;
	while (count < 127)
		check[count++] = 0;
	tmp = str1;
	while (*tmp)
		check[*tmp++] = 1;
	tmp = str2;
	while (*tmp)
		check[*tmp++] = 1;
	while (*str1)
	{
		if (check[*str1] == 1)
			write(1, str1, 1);
		check[*str1++] = 0;
	}
	while (*str2)
	{
		if (check[*str2] == 1)
			write(1, str2, 1);
		check[*str2++] = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(*(argv + 1), *(argv + 2));
	write(1, "\n", 1);
	return (0);
}
