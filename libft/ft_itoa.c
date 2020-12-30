#include "libft.h"

static int	ft_len_check(int	n, int	sign)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	if (sign < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ret;
	unsigned int	len;
	unsigned int	save;

	if (n < 0)
		save = -n;
	else
		save = n;
	len = ft_len_check(save, n);
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
			return (0);
	ret[len] = '\0';
	if (n < 0)
		ret[0] = '-';
	while (save > 0)
	{
		ret[len - 1] = save % 10 + 48;
		save = save / 10;
		len--;
	}
	return (ret);
}
