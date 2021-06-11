NAME = cub3d

CC = gcc

HEAD = -I includes -I minilibx

BONUS_HEAD = -I bonus/includes -I minilibx

FLAG = -Wall -Wextra -Werror $(HEAD) $(BONUS_HEAD)

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

BONUS_SRCS = bonus/srcs/main_bonus.c \
	bonus/srcs/setting_program_bonus.c \
	bonus/srcs/raycasting/player_bonus.c \
	bonus/srcs/raycasting/player_utils_bonus.c \
	bonus/srcs/raycasting/raycasting_bonus.c \
	bonus/srcs/raycasting/raycasting_utils_bonus.c \
	bonus/srcs/raycasting/key_bonus.c \
	bonus/srcs/raycasting/texture_bonus.c \
	bonus/srcs/parse/parse_bonus.c \
	bonus/srcs/parse/parse_utils_basic_bonus.c \
	bonus/srcs/parse/identifier/parse_identifier_bonus.c \
	bonus/srcs/parse/map/parse_map_bonus.c \
	bonus/srcs/parse/map/parse_map_validation_bonus.c \
	bonus/srcs/parse/gnl/get_next_line_bonus.c \
	bonus/srcs/parse/gnl/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(RM) $(BONUS_OBJS)
	make -C minilibx
	cp minilibx/libmlx.dylib libmlx.dylib
	$(CC) $(FLAG) $(OBJS) libmlx.dylib -o $(NAME)

bonus : $(BONUS_OBJS)
	$(RM) $(OBJS)
	make -C minilibx
	cp minilibx/libmlx.dylib libmlx.dylib
	$(CC) $(FLAG) $(BONUS_OBJS) libmlx.dylib -o $(NAME)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	make clean -C minilibx
	$(RM) $(NAME) libmlx.dylib

re : fclean all
