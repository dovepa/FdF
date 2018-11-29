/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:05:18 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/28 03:36:57 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_pixel(unsigned int *data, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	data[y * WIN_WIDTH + x] = color;
	return ;
}

static unsigned int ft_pixel_color(t_fdf *fdf, t_bresenham val, t_vector v1, t_vector v2)
{
	(void)fdf;
	(void)val;
	(void)v1;
	(void)v2;
	return(fdf->map->color);
}

static void	ft_bresenham_else(t_fdf *fdf, t_bresenham val, t_vector v1, t_vector v2)
{
	val.e = val.dy;
	while (val.i++ <= (val.dy / 2))
		{
			ft_pixel(fdf->img->data, v1.x, v1.y, ft_pixel_color(fdf, val, v1, v2));
			v1.y += val.yi;
			val.e -= val.dx;
			if (val.e <= 0 && val.dx != 0)
			{
				v1.x += val.xi;
				val.e += val.dy;
			}
		}
	return ;
}

void	ft_bresenham(t_fdf *fdf, t_vector v1, t_vector v2)
{
	t_bresenham val;
 
	val.dx = fabs((v2.x - v1.x) * 2);
	val.dy = fabs((v2.y - v1.y) * 2);
	val.xi = v2.x < v1.x ? -1 : 1;
	val.yi = v2.y < v1.y ? -1 : 1;
	val.i = 0;
	if ((val.e = val.dx) > val.dy)
		while (val.i++ <= (val.dx / 2))
		{
			ft_pixel(fdf->img->data, v1.x, v1.y, ft_pixel_color(fdf, val, v1, v2));
			v1.x += val.xi;
			val.e -= val.dy;
			if (val.e <= 0 && val.dy != 0)
			{
				v1.y += val.yi;
				val.e += val.dx;
			}
		}
	else 
		ft_bresenham_else(fdf, val, v1, v2);
	return ;
}
