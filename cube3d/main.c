/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:25:43 by wonchoi           #+#    #+#             */
/*   Updated: 2021/05/18 01:22:28 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "cub3d.h"

int	main(int argc, const char **argv)
{
	t_mlx->mlx_ptr = mlx_init();
	if (argc > 3 || argc == 1
			|| (argc == 3 && ft_strcmp("--save", argv[2]) != 0))
		return (-2);
	if (!init_game((char*)argv[1]))
		return (-1);
/*	if (argc = 3)
	{

	}
	else */
		init_mlx;
	return (0);
}
