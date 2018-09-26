/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/09/26 11:16:23 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void ft_draw(t_windows *w)
{
	// ft_bresenham(w->draw.mx + 3, 	w->draw.my + 25,	w->draw.mx + 200,	w->draw.my + 43, w->img.data, w->win_width,	w->draw.color);
	// ft_bresenham(w->draw.mx + 205,	w->draw.my + 62,	w->draw.mx + 10,	w->draw.my + 32, w->img.data, w->win_width,	w->draw.color);
	// ft_bresenham(w->draw.mx + 3,	w->draw.my + 299,	w->draw.mx + 249,	w->draw.my + 3, w->img.data, w->win_width,	w->draw.color);
	// ft_bresenham(w->draw.mx + 205,	w->draw.my + 3,		w->draw.mx + 10,	w->draw.my + 30, w->img.data, w->win_width,	w->draw.color);
	// ft_bresenham(w->draw.mx + 5,	w->draw.my + 50,	w->draw.mx + 30,	w->draw.my + 50, w->img.data, w->win_width,	w->draw.color);
	// ft_bresenham(w->draw.mx + 3,	w->draw.my + 0,		w->draw.mx + 3,		w->draw.my + 200, w->img.data, w->win_width, w->draw.color);
	// ft_bresenham(w->draw.mx + 2,	w->draw.my + 0,		w->draw.mx + 2,		w->draw.my + 200, w->img.data, w->win_width, w->draw.color);
	// ft_bresenham(w->draw.mx + 1,	w->draw.my + 50,	w->draw.mx + 50,	w->draw.my + 1, w->img.data, w->win_width,	w->draw.color);
	// ft_bresenham(w->draw.mx + 53,	w->draw.my + 4,		w->draw.mx + 4,		w->draw.my + 53, w->img.data, w->win_width,	w->draw.color);
	// ft_bresenham(w->draw.mx + 1,	w->draw.my + 1,		w->draw.mx + 30,	w->draw.my + 30, w->img.data, w->win_width,	w->draw.color);
	// ft_bresenham(w->draw.mx + 200,	w->draw.my + 200,	w->draw.mx + 100,	w->draw.my + 100, w->img.data, w->win_width,	w->draw.color);
	ft_bresenham(500,	400,	w->draw.mx,	w->draw.my, w->img.data, w->win_width,	w->draw.color);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img.img_ptr, 0, 0);
	return ;
}


int	main(int argc, char **argv)
{
	t_windows w;
	
	w.win_width = 1000;
	w.win_height = 800;
	w.draw.rcolor = 0;
	w.draw.colorn = 0;
	w.draw.color = WHITE;
	w.draw.mx = 0;
	w.draw.my = 0;

	if (argc != 2)
	{
		ft_usage("./fdf exemple_of_maps");
		return (1);
	}

	w.title = ft_strjoin("|--- 42 FdF ---| Map : ", argv[1]);
	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.win_width, w.win_height, w.title);
	w.img.img_ptr = mlx_new_image(w.mlx_ptr, w.win_width, w.win_height);
	w.img.data = (char *)mlx_get_data_addr(w.img.img_ptr, &w.img.bpp, &w.img.size_l, &w.img.endian);
	mlx_key_hook(w.win_ptr, ft_key, (void *)&w);
	mlx_hook(w.win_ptr, 6, 0, ft_mousemove, (void *)&w);
	mlx_hook(w.win_ptr, 4, 0, ft_mousedown, (void *)&w);
	mlx_hook(w.win_ptr, 5, 0, ft_mouseup, (void *)&w);
	
	ft_draw(&w);
	mlx_loop(w.mlx_ptr);

	return (0);
}	


/*mlx_destroy_image(w.mlx_ptr, w.img.img_ptr);*/
