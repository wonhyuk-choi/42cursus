NAME = libftprintf.a
HEADER = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_LIB = libft.a
AR = ar rc
RM = rm -f

SRCS =
OBJS = $(SRCS:.c=.o)

all = $(NAME)

%o: %.c $(HEADER)
	$(cc) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all
