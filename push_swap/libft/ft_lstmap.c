/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:51:27 by wonchoi           #+#    #+#             */
/*   Updated: 2021/03/21 19:57:15 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*n_next;

	if (lst == 0)
		return (0);
	ret = ft_lstnew(f(lst->content));
	if (ret == 0)
		return (0);
	tmp = ret;
	lst = lst->next;
	while (lst)
	{
		n_next = ft_lstnew(f(lst->content));
		if (n_next == 0)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		tmp->next = n_next;
		tmp = n_next;
		lst = lst->next;
	}
	return (ret);
}
