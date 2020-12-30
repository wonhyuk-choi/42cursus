#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

char **ft_split(char const *s, char c)
{
	char	**ret;

	if (!(ret = (char**)malloc(sizeof(char*) * word_count(s,c) + 1)))
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			}
	}

	return (ret);
}
