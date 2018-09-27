/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:12:15 by dpalombo          #+#    #+#             */
/*   Updated: 2018/09/27 15:42:25 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include "mlx_rgb.c"

// int ft_mousemove(int x,int y, t_windows *w)
// {
// 	{w->draw.mx = 0;
// 	w->draw.mx = x;
// 	w->draw.my = y;
// 	ft_draw(w);}
// 	return (0);
// }

// int ft_mousedown(int button, int x,int y, t_windows *w)
// {
// 	(void *)x;
// 	(void *)y;
// 	(void *)w;
// 	return (button);
// }

// int ft_mouseup(int button, int x,int y, t_windows *w)
// {
// 	(void *)x;
// 	(void *)y;
// 	(void *)w;
// 	return (button);
// }
void ft_gradient(t_windows w)
{
	int r;
	int g;
	int b;

	r = ((w->draw.color >> 16) & 11111111);
	g = ((color >> 8) & 11111111);
	b = (color & 11111111);
	while (r < 255 || g < 255 || b < 255)
	{
		if (r < 255)
			r++;
		if (g < 255)
			g++;
		if (b < 255)
			b++;

	}
	
}

int ft_color(t_windows *w)
{
	if (w->draw.rcolor == 1)
	{
		w->draw.colorn += 1;
		if (w->draw.colorn > 751)
			w->draw.colorn = 0;
		w->draw.color = mlx_col_name[w->draw.colorn].color;
		ft_draw(w);
		usleep(100000);
	}
	else
	{
		w->draw.rcolor = 0;
		w->draw.color = RED;
		ft_draw(w);
	}
	return (0);
}

int ft_key(int key, t_windows *w)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window((*w).mlx_ptr, (*w).win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (key == C_COLOR)
	{
		mlx_loop_hook(w->mlx_ptr, ft_color, w);
		w->draw.rcolor++;
	}
	return (0);
}
