#include "libft.h"

static void	printing_nbr(int	n,	int fd)
{
	char	c;

	if (n >= 10)
		printing_nbr(n / 10, fd);
	c = n % 10 + 48;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int	n, int	fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n = -n;
		}
		printing_nbr(n, fd);
	}
	
