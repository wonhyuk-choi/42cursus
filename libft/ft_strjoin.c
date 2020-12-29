#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(tmp = malloc(len)))
		return (0);
	ft_strlcpy(tmp, s1, len);
	ft_strlcat(tmp, s2, len);
	return (tmp);
}
