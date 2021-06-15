NAME = fractol

HEADER = -I includes -I minilibx

CC = gcc

CFLAGS = -Wall -Wextra -Werror $(HEADER)

LIB = minilibx

RM = -rm -rf

SRCS = srcs/fractol.c	\

OBJS = $(SRCS:.c=.o)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		make -C minilibx
		cp minilibx/libmlx.dylib libmlx.dylib
		$(CC) $(CFLAGS) $(OBJS) libmlx.dylib -o $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		make clean -C minilibx
		$(RM) $(NAME) libmlx.dylib

re : fclean all

.phony = make clean fclean re
