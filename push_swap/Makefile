NAME = push_swap.out
HEADER = push_swap.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_LIB = libft.a
AR = ar rc
RM = rm -f

SRCS =	fill_stack_a.c			\
		push_swap.c				\
		push_swap_error.c		\
		fill_stack_a.c			
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $^

bonus : all

%o: %.c $(HEADER)
	$(cc) $(CFLAGS) -c $< -o $@

clean :
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean : clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re : fclean all

.phony = make clean fclean re
