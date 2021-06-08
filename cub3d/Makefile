NAME = cub3d

CC = gcc

HEAD = -I includes -I minilibx

FLAG = -Wall -Wextra -Werror $(HEAD) -g3 -fsanitize=address

RM = rm -rf

SRCS = srcs/main.c \
	srcs/setting_program.c \
	srcs/raycasting/player.c \
	srcs/raycasting/raycasting.c \
	srcs/raycasting/raycasting_utils.c \
	srcs/raycasting/key.c \
	srcs/raycasting/texture.c \
	srcs/parse/parse.c \
	srcs/parse/parse_utils_basic.c \
	srcs/parse/identifier/parse_identifier.c \
	srcs/parse/map/parse_map.c \
	srcs/parse/map/parse_map_validation.c \
	srcs/parse/gnl/get_next_line.c \
	srcs/parse/gnl/get_next_line_utils.c

OBJS = $(addprefix objs/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	make -C minilibx
	cp minilibx/libmlx.dylib libmlx.dylib
	$(CC) $(FLAG) $(OBJS) libmlx.dylib -o $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(FLAG) -c $(SRCS)
	mv -f *.o objs

clean :
	$(RM) objs/*.o

fclean : clean
	make clean -C minilibx
	$(RM) $(NAME) libmlx.dylib

re : fclean all