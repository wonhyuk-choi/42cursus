#include "libft.h"

int	strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;


	 i = 0;
	 while (i < n && (*str1 || *str2))
	 {
		if (*str1 != *str2)
			return (*(unsigned char*)str1 - *(unsigned char*)str2);
		i++;
		str1++;
		str2++;
	 }
	 return (0);
}
