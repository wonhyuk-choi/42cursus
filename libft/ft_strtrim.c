#include "libft.h"

int		is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*ret;
	char	*start;
	char	*end;
	size_t	len;

	if (!*s1)
		return (0);
	start = (unsigned char *)s1;
	end = start + ft_strlen(s1);
	while (*start && is_set(*start, set))
		start++;
	while (start < end && is_set(*(end - 1), set))
		end--;
	len = end - start + 1;
	if(!(ret = malloc(len)))
		return (0);
	ft_strlcpy(ret, start, len);
	return (ret);
}
