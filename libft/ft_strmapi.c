#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	if (s == 0 && f == 0)
		return (0);
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (s[i])
	{
		ret[i] = f(i,s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
