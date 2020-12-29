include "libft.h"

int	atoi(const char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((*nptr >= 9 && *npr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = sign * -1;
		nptr++
	}
	while (*nptr >= 0 && *nptr <= 9)
	{
		i = i * 10 + *nptr - '0';
		nptr++;
	}
	i = i * sign;
	return (i);
}
