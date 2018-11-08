/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:12:15 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/08 14:38:44 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include "mlx_rgb.c"



int	ft_mouseup(int button, int x,int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	fdf->mouse->button = button - 1;
	return (0);
}


int	ft_mousedown(int button, int x,int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	fdf->mouse->button = button;
	return (0);
}

int	ft_mousemove(int x,int y, t_fdf *fdf)
{
	if (fdf->mouse->button == 1)
	{
		fdf->mouse->xpast = fdf->mouse->x;
		fdf->mouse->ypast = fdf->mouse->y;
		fdf->mouse->x = x;
		fdf->mouse->y = y;
		//ft_draw(fdf);
	}
	return (0);
}

int ft_color(t_fdf *fdf)
{
	int x;

	x = 0;
	if (fdf->map->ready == 1)
	{
		x += 1;
		if (x > 751)
			x = 0;
		fdf->map->color = mlx_col_name[x].color;
		//ft_draw(fdf); 
		usleep(100000);
	}
	else
	{
		fdf->map->ready = 0;
		fdf->map->color = DEFAULTC;
		//ft_draw(fdf);
	}
	return (0);
}

int ft_key(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == ESC_KEY)
		 exit(EXIT_SUCCESS);
	if (key == C_COLOR)
	{
		mlx_loop_hook(fdf->mlx_ptr, ft_color, fdf);
		fdf->map->ready++;
	}
	if (key == MORE_KEY || key == LESS_KEY)
	{
		fdf->map->zoom += 1;
		//ft_draw(fdf);
	}
	if (key == LESS_KEY)
	{
		fdf->map->zoom -= 1;
		//ft_draw(fdf);
	}
	return (0);
}