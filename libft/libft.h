#ifdef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct	s_list	*next;
}					t_lsit;

#endif
