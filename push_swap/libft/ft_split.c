/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:51:27 by wonchoi           #+#    #+#             */
/*   Updated: 2021/03/21 19:59:21 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			cnt++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static void		ft_partcopy(char *ret, char const *s, size_t begin, size_t end)
{
	size_t	i;

	i = 0;
	while (begin < end)
	{
		ret[i] = s[begin];
		i++;
		begin++;
	}
	ret[i] = '\0';
}

static char		**memfree(char **ret, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (0);
}

static char		**split(char const *s, char c, char **ret)
{
	size_t	i;
	size_t	j;
	size_t	begin;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		begin = i;
		if (s[i] != '\0' && s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			ret[j] = (char *)malloc(sizeof(char) * (i - begin + 1));
			if (ret[j] == 0)
				return (memfree(ret, j));
			ft_partcopy(ret[j], s, begin, i);
			j++;
		}
		else if (s[i] != '\0')
			i++;
	}
	ret[j] = 0;
	return (ret);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;

	if (s == 0)
		return (0);
	i = word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	if (ret == 0)
		return (0);
	ret[i] = 0;
	if (i == 0)
		return (ret);
	ret = split(s, c, ret);
	return (ret);
}
