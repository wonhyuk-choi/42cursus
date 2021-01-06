/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:51:27 by wonchoi           #+#    #+#             */
/*   Updated: 2021/01/06 14:38:39 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, voif (*f)(void *))
{
	if (lst == '\0' || f == '\0')
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
