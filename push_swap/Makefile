NAME = push_swap
HEADER = push_swap.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ./libft/libft.a
LIB_PATH = ./libft
AR = ar rc
RM = rm -f

SRCS = $(wildcard *.c)		
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

bonus : all

%o: %.c $(HEADER)
	$(cc) $(CFLAGS) -c $< -o $@

clean :
	make clean -C $(LIB_PATH)
	$(RM) $(OBJS)

fclean : clean
	make fclean -C $(LIB_PATH)
	$(RM) $(NAME)

re : fclean all

.phony = make clean fclean re
