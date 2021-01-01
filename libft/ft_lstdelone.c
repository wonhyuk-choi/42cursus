#include "libft.h"

void	ft_lstdelone(t_list	*lst, void	(*del)(void *))
{
	if (lst == '\0')
		return ;
	del(lst->content);
	free(lst);
}
