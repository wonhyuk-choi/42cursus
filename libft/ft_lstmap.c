#include "libft.h"

t_list	*ft_lstmap(t_list	*lst, void	*(*f)(void *), void	(*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*n_next;

	if (lst  == '\0')
		return (0);
	if ((ret = ft_lstnew(f(lst->content))) == '\0')
		return (0);
	tmp = ret;
	lst = lst->next;
	while (lst)
	{
		if ((n_next = ft_lstnew(f(lst->content))) == '\0')
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
