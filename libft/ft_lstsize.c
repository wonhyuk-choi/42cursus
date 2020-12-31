#include "ibft.h"

int	ft_lstsize(t_list	*lst)
{
	int	num;

	num = 0;
	while(lst != '\0')
	{
		lst = lst->next;
		num++;
	}
	return (num);
}
