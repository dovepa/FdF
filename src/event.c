/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 19:42:46 by dpalombo          #+#    #+#             */
/*   Updated: 2018/06/07 17:26:25 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static int		ft_vert(t_windows *windows, int i)
{
	char *ph = "MENU : <- L & R -> |\n|   Up & Down |\n| +  Scale  - |\n|  Quit : ESC |";
	if (i == 1)
		mlx_string_put((*windows).mlx_ptr, (*windows).win_ptr, 1, 1, 0xFFFFFF, ph);
	else
		mlx_clear_window((*windows).mlx_ptr, (*windows).win_ptr);
	return (0);
}

static int		ft_hor(t_windows *windows, int i)
{
	if (i == 1)
	{
		int x = 1;
		int y = 1;
		while (y < 800)
		{
			while (x < 600)
			{
				mlx_pixel_put((*windows).mlx_ptr, (*windows).win_ptr, y, x, 0xFFFFFF);
				x += 1;
			}
			x = 1;
			y += 1;
		}
	}
	else
	{
		int x = 1;
		int y = 1;
		while (y < 800)
		{
			while (x < 600)
			{
				mlx_pixel_put((*windows).mlx_ptr, (*windows).win_ptr, y, x, 0xc68c40);
				x += 1;
			}
			x = 1;
			y += 1;
		}
	}
	return (0);
}
static int		ft_scale(t_windows *windows, int i)
{
	if (i == 1)
	{
		int x = 1;
		int y = 1;
		while (y < 800)
		{
			while (x < 600)
			{
				mlx_pixel_put((*windows).mlx_ptr, (*windows).win_ptr, y, x, 0xFFFFFF);
				x += 1;
			}
			x = 1;
			y += 1;
		}
	}
	else
	{
		int x = 1;
		int y = 1;
		while (y < 800)
		{
			while (x < 600)
			{
				mlx_pixel_put((*windows).mlx_ptr, (*windows).win_ptr, y, x, 0xc68c40);
				x += 1;
			}
			x = 1;
			y += 1;
		}
	}
	return (0);
}

int		ft_how_to(int key, t_windows *windows)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window((*windows).mlx_ptr, (*windows).win_ptr);
		exit(EXIT_SUCCESS);
	}
	else if (key == UP_KEY)
		return(ft_vert(windows, 1));
	else if (key == DOWN_KEY)
		return(ft_vert(windows, -1));
	else if (key == RIGHT_KEY)
		return(ft_hor(windows, 1));
	else if (key == LEFT_KEY)
		return(ft_hor(windows, -1));
	else if (key == MORE_KEY)
		return(ft_scale(windows, 1));
	else if (key == LESS_KEY)
		return(ft_scale(windows, -1));
	return (0);
}


	/*	int x = 1;
		int y = 1;
		while (y < 800)
		{
			while (x < 600)
			{
				mlx_pixel_put((*windows).mlx_ptr, (*windows).win_ptr, y, x, 0xFFFFFF);
				x += 1;
			}
			x = 1;
			y += 1;
		}
	*/