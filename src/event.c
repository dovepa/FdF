/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:12:15 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/28 11:22:40 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include "mlx_rgb.c"

int ft_rotate(t_fdf *fdf)
{
	if (fdf->arrow->rotate == 1)
	{
		usleep(1000);
		fdf->arrow->x += 0.01;
		ft_draw(fdf);
	}
	else
		fdf->arrow->rotate = 0;
	return (0);
}

int ft_king(t_fdf *fdf)
{
	
	if (fdf->arrow->rotate == 1)
	{
		usleep(1000);
		if (fdf->map->cn > 751)
			fdf->map->cn  = 0;
		if ((fdf->map->ready++ % 10) == 0)
			fdf->map->color = mlx_col_name[fdf->map->cn].color;
		fdf->map->cn++;
		fdf->arrow->x += 0.01;
		ft_draw(fdf);
	}
	else
	{
		fdf->arrow->rotate = 0;
		fdf->map->color = DEFAULTC;
		ft_draw(fdf);
	}
	return (0);
}

int ft_color(t_fdf *fdf)
{
	if (fdf->map->ready == 1)
	{
		if (fdf->map->cn > 751)
			fdf->map->cn  = 0;
		usleep(10000);
		fdf->map->color = mlx_col_name[fdf->map->cn].color;
		ft_draw(fdf); 
		fdf->map->cn++;
	}
	else
	{
		fdf->map->ready = 0;
		fdf->map->color = DEFAULTC;
		ft_draw(fdf);
	}
	return (0);
}

int ft_key(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == ESC_KEY)
		ft_exit(fdf);
	if (key == C_COLOR)
	{
		mlx_loop_hook(fdf->mlx_ptr, ft_color, fdf);
		fdf->map->ready++;
	}
	if (key == R_ROTATE)
	{
		mlx_loop_hook(fdf->mlx_ptr, ft_rotate, fdf);
		fdf->arrow->rotate++;
	}
	if (key == KING)
	{
		mlx_loop_hook(fdf->mlx_ptr, ft_king, fdf);
		fdf->arrow->rotate++;
	}
	return (0);
}
