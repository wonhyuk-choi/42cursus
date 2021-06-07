/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:51:27 by wonchoi           #+#    #+#             */
/*   Updated: 2021/03/21 20:00:25 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	sub_len;

	if (!s || ft_strlen(s) < start || len == 0)
		return (ft_strdup(""));
	sub_len = ft_strlen(s) - start;
	if (sub_len < len)
		tmp = (char *)malloc(sizeof(char) * (sub_len + 1));
	else
		tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == 0)
		return (0);
	ft_strlcpy(tmp, s + start, len + 1);
	return (tmp);
}
