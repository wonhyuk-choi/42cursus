#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;

	if (dest == 0 || src == 0)
		return (0);
	tmp = dest;
	if (dest <= src)
	{
		while (n--)
			*(char *)dest++ = *(char *)src++;
	}
	else
	{
		dest += n;
		src += n;
		while (n--)
			*(char *)--dest = *(char *)--src;
	}
	return(tmp);
}
