NAME = fractol

HEADER = -I includes -I minilibx -I libft

CC = gcc -g3 -fsanitize=address

CFLAGS =  $(HEADER)

LIB_MLX = minilibx

LIB_LIBFT = libft

RM = -rm -rf

SRCS =	srcs/main.c				\
		srcs/check_fractol.c	\
		srcs/draw_fractol.c		\
		srcs/select_fractol.c	\
		srcs/key.c

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
