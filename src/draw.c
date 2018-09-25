/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:05:18 by dpalombo          #+#    #+#             */
/*   Updated: 2018/09/25 14:12:22 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void ft_pixel(int x,int y, char *data, int win_width, unsigned int color)
{
	int r;
	int g;
	int b;

	r = ((color >> 16) & 11111111);
	g = ((color >> 8) & 11111111);
	b = (color & 11111111);
	data[y * win_width * 4 + x * 4 + 2] = (char) r;
	data[y * win_width * 4 + x * 4 + 1] = (char) g;
	data[y * win_width * 4 + x * 4] = (char) b;
	return ;
}

void ft_bresenham(int x1, int y1, int x2, int y2, char *data, int win_width, unsigned int color)
{
	int e;
	int xi;
	int yi;
	int dx;
	int dy;
	int i;
	
	i = 0;
	dx = ((x2 - x1) * 2) > 0 ? ((x2 - x1) * 2) : ((x2 - x1) * -2);
	dy = ((y2 - y1) * 2) > 0 ? ((y2 - y1) * 2) : ((y2 - y1) * -2);
	xi = x2 < x1 ? -1 : 1;
	yi = y2 < y1 ? -1 : 1;
	e = dy;
	if ((e = dx) > dy)
	{
		while (i++ <= (dx / 2))
		{
			ft_pixel(x1, y1, data, win_width, color);
			x1 += xi;
			e -= dy;
			if (e <= 0 && dy != 0)
			{
				y1 += yi;
				e += dx;
			}
		}
	}
	else 
	{
		while (i++ <= (dy / 2))
		{
			ft_pixel(x1, y1, data, win_width, color);
			y1 += yi;
			e -= dx;
			if (e <= 0 && dx != 0)
			{
				x1 += xi;
				e += dy;
			}
		}
	}
	return ;
}
