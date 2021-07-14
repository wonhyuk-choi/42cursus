# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 21:08:59 by wonchoi           #+#    #+#              #
#    Updated: 2021/07/14 23:12:31 by wonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADER = pipex.h
CC = gcc
CFALGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	pipex.c			\
		pipex_error.c	\
		pipex_util.c	\
		pipex_util2.c	\
		pipex_util3.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFALGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFALGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony = make clean fclean re
