#include "libft.h"

void ft_*memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if ((*(unsigned char*)s) == (unsigned char) c)
			return ((void*) s);
		s++;
		n--;
	}
	return (0);
}
