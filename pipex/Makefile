NAME = pipex
HEADER = pipex.h
CC = gcc
CFALGS = -Wall -Wextra -Werror
LIB = ./libft/libft.a
LIB_PATH = ./libft
RM = rm -f

SRCS =	pipex.c			\
		pipex_error.c	\
		redirect.c		\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_PATH)
	$(CC) $(CFALGS) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFALGS) -c $< -o $@

clean :
	make clean -C $(LIB_PATH)
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) $(LIB)

re : fclean all

.phony = make clean fclean re