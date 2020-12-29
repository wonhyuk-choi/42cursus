#include "libft.h"

size_t strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	
	i = 0;
	while (*dst != '\0' || i < size)
	{
		dst++;
		i++;
	}
	while (*src != '\0' || i < size - 1)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < size)
		*dst = 0;
	while (*src)
	{
		i++;
		src++
	}
	return (i);
}
