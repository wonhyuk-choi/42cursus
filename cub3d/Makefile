NAME = cub3d

CC = gcc

HEAD = -I includes -I minilibx

BONUS_HEAD = -I bonus/includes -I minilibx

FLAG = -Wall -Wextra -Werror $(HEAD) $(BONUS_HEAD) -g3 -fsanitize=address

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

BONUS_SRCS = $(addprefix bonus/, $(SRCS:.c=_bonus.c))

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C minilibx
	cp minilibx/libmlx.dylib libmlx.dylib
	$(CC) $(FLAG) $(OBJS) libmlx.dylib -o $(NAME)

bonus : $(BONUS_OBJS)
	make -C minilibx
	cp minilibx/libmlx.dylib libmlx.dylib
	$(CC) $(FLAG) $(BONUS_OBJS) libmlx.dylib -o $(NAME)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	make clean -C minilibx
	$(RM) $(NAME) libmlx.dylib

re : fclean all