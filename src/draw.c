/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:05:18 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/30 13:57:12 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static double ft_dv(t_bresenham val, t_vector v1)
{
	double dv;

	if (val.dx > val.dy)
		if (v1.x == val.vec[0].x)
			dv = (double)0;
		else if (v1.x == val.vec[1].x)
			dv = (double)1;
		else
			dv = (v1.x - val.vec[0].x) / (val.vec[1].x - val.vec[0].x);
	else
		if (v1.y == val.vec[0].y)
			dv = (double)0;
		else if (v1.y == val.vec[1].y)
			dv = (double)1;
		else
			dv = (v1.y - val.vec[0].y) / (val.vec[1].y - val.vec[0].y);
	return (dv);
}

static int ft_pixel_color(t_fdf *fdf, t_bresenham val, t_vector v1, t_vector v2)
{
	double dv;
	int r;
	int g;
	int b;
	int color;
	
	if (v1.color == DEFAULTC)
		v1.color = fdf->map->color;
	if (v2.color == DEFAULTC)
		v2.color = fdf->map->color;
	if (v1.color == v2.color)
		return(v1.color);
	dv = ft_dv(val, v1);
 	r = (((int)((v1.color >> 16) & 255) + (((int)((v2.color >> 16) & 255)) - \
	 ((int)((v1.color >> 16) & 255))) * dv));
	g = (((int)((v1.color >> 8) & 255) + (((int)((v2.color >> 8) & 255 )) - \
	((int)((v1.color >> 8) & 255))) * dv));
 	b = (((int)(v1.color & 255) + (((int)(v2.color & 255)) - \
	 ((int)(v1.color & 255))) * dv));
	color = r << 16 | g << 8 | b;
	if (color == DEFAULTC)
		return(fdf->map->color);
	return(color);
}

void	ft_pixel(unsigned int *data, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	data[y * WIN_WIDTH + x] = color;
	return ;
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
	val.vec[0] = v1;
	val.vec[1] = v2;
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
