/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:10:51 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/15 21:04:16 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_burningship(double r, double i, t_data *data)
{
	int		j;
	double	tmp;

	j = 0;
	while (j < data->max && r * r + i * i < 4)
	{
		tmp =  r * r - i * i - data->r;
		i = fabs(2 * r * i) - data->i;
		r = tmp;
		j++;
	}
	return (j);
}
	