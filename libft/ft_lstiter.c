#include "libft.h"

void	ft_lstiter(t_list	*lst, voif (*f)(void *))
{
	if (lst == '\0' || f == '\0')
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
