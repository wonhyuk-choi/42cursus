#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*(char *)dest = *(char *)src;
		n--;
		dest++;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dest);
		src++;
	}
	return (0);
}
