NAME = fractol

HEADER = -I includes -I minilibx -I libft

CC = gcc

CFLAGS =  $(HEADER)

LIB_MLX = minilibx

LIB_LIBFT = libft

RM = -rm -rf

SRCS =	srcs/fractol.c			\
		srcs/function.c			\
		srcs/setting_value.c	\
		srcs/julia.c			\
		srcs/mandelbrot.c		\
		srcs/burning_ship.c		\
		srcs/key.c

OBJS = $(SRCS:.c=.o)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		make -C minilibx
		make -C libft
		cp minilibx/libmlx.dylib libmlx.dylib
		cp libft/libft.a libft.a
		$(CC) $(CFLAGS) $(OBJS) libmlx.dylib libft.a -o $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		make clean -C minilibx
		make clean -C libft
		$(RM) $(NAME) libmlx.dylib libft.a

re : fclean all

.phony = make clean fclean re
