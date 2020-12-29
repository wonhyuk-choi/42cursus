#include "libft.h"

char	*ft_strdup(const char	*s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!(tmp = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	while (i < ft_strlen(s))
	{
		tmp[i] = s[i]
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
