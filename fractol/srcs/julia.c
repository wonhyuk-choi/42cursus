/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:41:25 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/15 20:22:35 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_julia(double r, double i, t_data *data)
{
	int		j;
	double	tmp;

	j = 0;
	while (j < data->max && r * r + i * i < 4)
	{
		tmp = r;
		r = tmp * tmp - i * i + data->mr;
		i = 2 * tmp * i + data->mi;	
		j++;
	}
	return (j);
}
