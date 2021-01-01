#include "lisbft.h"

void	ft_lstclear(t_list	**lst, void	(*del)(void *))
{
	t_list	*next;
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		ft_lstdelone(tmp, del)
		tmp = next;
	}
	*lst = 0;
}
