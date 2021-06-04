NAME = push_swap
HEADER = push_swap.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ./libft/libft.a
LIB_PATH = ./libft
RM = rm -f

SRCS =	do_p.c				\
		do_rr.c				\
		do_rrr.c			\
		do_s.c				\
		fill_stack_a.c		\
		find_median.c		\
		find_small_big.c	\
		frame_len.c			\
		move_logic.c		\
		push_median.c		\
		push_one_six.c		\
		push_one_six_sub.c	\
		push_swap.c			\
		push_swap_error.c	\
		reset_move_value.c	\
		stack_function.c	\
		under_100.c			\
		under_5.c			\
		over_100.c			
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

bonus : all

%o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C $(LIB_PATH)
	$(RM) $(OBJS)

fclean : clean
	make fclean -C $(LIB_PATH)
	$(RM) $(NAME)

re : fclean all

.phony = make clean fclean re
