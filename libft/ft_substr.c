#include "libft.h"

char *ft_substr(char const	*s, unsigned int	start, size_t	len)
{
	char			*tmp;
	
	if (!s || strlen(s) < start || !len)
		return (strdup(""));
	if (!(tmp = malloc(len + 1)))
		return (0);
	ft_strlcpy(tmp, s + start, len);
	return (tmp);
}
