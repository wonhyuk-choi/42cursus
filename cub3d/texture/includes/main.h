#ifndef MAIN_H
# define MAIN_H

# include "raycasting.h"

char	*setting_program(t_cub3d **cub3d, char *map_path);
char	*map_path_str(char *str);
void	free_cub3d(t_cub3d *cub3d);

#endif
