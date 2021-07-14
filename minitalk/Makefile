# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 00:27:10 by wonchoi           #+#    #+#              #
#    Updated: 2021/07/15 02:55:39 by wonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

NAME_CLIENT	= client

CC = gcc $(FLAGS)

FLAGS = -Wall -Werror -Wextra

SERVER_SRC = server.c server_util.c server_util2.c

CLIENT_SRC = client.c client_util.c

SERVER_SRC_OBJ	= $(SERVER_SRC:.c=.o)

CLIENT_SRC_OBJ	= $(CLIENT_SRC:.c=.o)

all :	fclean $(SERVER_SRC_OBJ) $(CLIENT_SRC_OBJ)
		@$(CC) $(SERVER_SRC) -I minitalk.h -o server
		@$(CC) $(CLIENT_SRC) -I minitalk.h -o client

clean :
	@rm -rf ./*.o

fclean: clean
	@rm -rf $(NAME) $(NAME_CLIENT)

re: fclean all

.PHONY : bonus all clean fclean