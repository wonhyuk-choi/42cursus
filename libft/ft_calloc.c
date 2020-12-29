#include "libft.h"

void	ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (!(p = malloc(nmemb * size)))
		return (0);
	ft_bzero(p, nmemb * size);
	return (p);
}
