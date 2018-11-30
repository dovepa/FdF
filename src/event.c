/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:12:15 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/30 01:44:09 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static int ft_colornum(int a)
{
	int colortab[20];

	colortab[0] =	0x778899;
	colortab[1] =	0x80;
	colortab[2] =	0x483d8b;
	colortab[3] =	0x8b4513;
	colortab[4] =	0xdeb887;
	colortab[5] =	0x838b83;
	colortab[6] =	0x8b8386;
	colortab[7] =	0xe0eeee;
	colortab[8] =	0x836fff;
	colortab[9] =	0x404040;
	colortab[10] =	0x8c8c8c;
	colortab[11] =	0xe3e3e3;
	colortab[12] =	0x458b74;
	colortab[13] =	0x8b8b;
	colortab[14] =	0xfa8072;
	colortab[15] =	0xee1289;
	colortab[16] =	0xcd919e;
	colortab[17] =	0x9b30ff;
	colortab[18] =	0x5d478b;
	colortab[19] =	0x8b7b8b;
	return(colortab[a]);
}

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
		if (fdf->map->cn > 19)
			fdf->map->cn  = 0;
		if ((fdf->map->ready++ % 10) == 0)
			fdf->map->color = ft_colornum(fdf->map->cn);
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
		if (fdf->map->cn > 19)
			fdf->map->cn  = 0;
		usleep(10000);
		fdf->map->color = ft_colornum(fdf->map->cn);
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
