# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonchoi <wonchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 12:00:52 by wonchoi           #+#    #+#              #
#    Updated: 2022/05/18 18:08:23 by wonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

HEADER = PhoneBook.hpp

CC = c++

FLAG = -std=c++98 -Wall -Wextra -Werror

SRCS = PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)

RM = -rm -rf

all	: $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(FLAG) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		: fclean all

.phony = make clean fclean re