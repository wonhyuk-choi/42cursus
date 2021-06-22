/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonchoi <wonchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:26:56 by wonchoi           #+#    #+#             */
/*   Updated: 2021/06/17 22:00:56 by wonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	int					i;
	const unsigned char	*c1;
	const unsigned char	*c2;

	c1 = (const unsigned char *)s1;
	c2 = (const unsigned char *)s2;
	i = 0;
	while (c1[i] && c1[i] == c2[i])
		i++;
	return (c1[i] - c2[i]);
}

int	check_fractol(char *name, t_fractol *fractol)
{
	if (!(ft_strcmp("mandelbrot", name)))
	{
		fractol->fractol_num = 1;
		return (1);
	}
	if (!(ft_strcmp("julia", name)))
	{
		fractol->fractol_num = 2;
		return (1);
	}
	if (!(ft_strcmp("burningship", name)))
	{
		fractol->fractol_num = 3;
		return (1);
	}
	else
		return (0);
}