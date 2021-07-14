# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 18:31:13 by wonchoi           #+#    #+#              #
#    Updated: 2021/07/14 18:31:14 by wonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = -I includes

CC = gcc -Wall -Wextra -Werror

CFLAGS = $(HEADER)

RM = -rm -rf

SRCS =	srcs/action.c		\
		srcs/init.c			\
		srcs/main.c			\
		srcs/monitering.c	\
		srcs/parse.c		\
		srcs/time.c

OBJS = $(SRCS:.c=.o)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.phony = make clean fclean re