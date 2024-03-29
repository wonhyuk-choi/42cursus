/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:07:04 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/22 15:52:00 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_mandelbrot(double r, double i, t_data *data)
{
	int		j;
	double	m_r;
	double	m_i;
	double	tmp;

	j = 0;
	m_i = 0;
	m_r = 0;
	while (j < data->max && m_r * m_r + m_i * m_i < 4)
	{
		tmp = m_r;
		m_r = tmp * tmp - m_i * m_i + r;
		m_i = 2 * tmp * m_i + i;
		j++;
	}
	return (j);
}
