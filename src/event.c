/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:12:15 by dpalombo          #+#    #+#             */
/*   Updated: 2018/09/26 11:32:50 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include "mlx_rgb.c"

//  static int ft_rcolor(t_windows *w)
// {
// 	if (w->draw.rcolor == 1)
// 	{
// 		w->draw.colorn += 1;
// 		if (w->draw.colorn > 751)
// 			w->draw.colorn = 0;
// 		sleep(3);
// 		w->draw.color = mlx_col_name[w->draw.colorn].color;
// 	}
// 	else
// 		w->draw.rcolor = 0;
// 	ft_draw(w);
// 	return (0); 
// }

 static int ft_rcolorbasic(t_windows *w)
{
		w->draw.colorn += 1;
		if (w->draw.colorn > 751)
			w->draw.colorn = 0;
		w->draw.color = mlx_col_name[w->draw.colorn].color;
		ft_draw(w);
		return (0);
}



int ft_mousemove(int x,int y, t_windows *w)
{
	if (ft_mousedown == 1 && ft_mouseup == 0)
	{w->draw.mx = 0;
	w->draw.mx = x;
	w->draw.my = y;
	ft_draw(w);}
	return (0);
}

int ft_mousedown(int button, int x,int y, t_windows *w)
{
	(void *)x;
	(void *)y;
	(void *)w;
	return (button);
}

int ft_mouseup(int button, int x,int y, t_windows *w)
{
	(void *)x;
	(void *)y;
	(void *)w;
	return (button);
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
		// mlx_loop_hook(w->mlx_ptr, ft_rcolor, (void *)w);
		// w->draw.rcolor++;
		ft_rcolorbasic(w);
	}
	if (key == R_COLOR)
	{
		// mlx_loop_hook(w->mlx_ptr, ft_rcolor, (void *)w);
		// w->draw.rcolor++;
		mlx_clear_window(w->mlx_ptr, w->win_ptr);
	}
	return (0);
}
