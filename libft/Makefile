NAME = libft.a
HEADER = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

BSRCS = ft_lstnew.c ft_lstclear.c ft_lstlast.c ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c ft_lstadd_front.c ft_lstiter.c ft_lstnew.c
SRCS = ft_memmove.c ft_strlen.c ft_memset.c ft_strmapi.c ft_atoi.c ft_putchar_fd.c ft_strncmp.c ft_bzero.c ft_putendl_fd.c ft_strnstr.c ft_calloc.c ft_putnbr_fd.c ft_strrchr.c ft_isalnum.c ft_putstr.fd.c ft_strtrim.c ft_isalpha.c ft_split.c ft_substr.c ft_isascii.c ft_strchr.c ft_tolower.c ft_isdigit.c ft_memccpy.c ft_strdup.c ft_toupper.c ft_isprint.c ft_memchr.c ft_strjoin.c ft_itoa.c ft_memcmp.c ft_strlcat.c ft_memcpy.c ft_strlcpy.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(BOBJS) $(OBJS)
	$(AR) $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)


fclean: clean	
	$(RM) $(NAME)

re: fclean all
