# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 12:00:52 by wonchoi           #+#    #+#              #
#    Updated: 2022/05/06 14:24:56 by wonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

RM = -rm -rf

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAG) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		: fclean all

.phony = make clean fclean re