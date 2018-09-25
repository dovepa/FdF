/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/09/25 14:13:02 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	main(int argc, char **argv)
{
	t_windows w;
	
	w.win_width = 300;
	w.win_height = 300;

	if (argc != 2)
	{
		ft_usage("./fdf exemple_of_maps");
		return (1);
	}

	w.title = ft_strjoin("|--- 42 FdF ---| Map : ", argv[1]);
	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.win_width, w.win_height, w.title);
	w.img.img_ptr = mlx_new_image(w.mlx_ptr, w.win_width, w.win_height);
	w.img.data = (char *)mlx_get_data_addr(w.img.img_ptr, &w.img.bpp,
		&w.img.size_l, &w.img.endian);

	ft_bresenham(3, 25, 200, 43, w.img.data, w.win_width, BLUE);
	ft_bresenham(205, 62, 10, 32, w.img.data, w.win_width, BLUE);

	ft_bresenham(3, 299, 249, 3, w.img.data, w.win_width, BLUE);
	ft_bresenham(205, 3, 10, 30, w.img.data, w.win_width, BLUE);

	ft_bresenham(5, 50, 30, 50, w.img.data, w.win_width, BLUE);
	ft_bresenham(3, 0, 3, 200, w.img.data, w.win_width, BLUE);
		ft_bresenham(2, 0, 2, 200, w.img.data, w.win_width, RED);


	ft_bresenham(1, 50, 50, 1, w.img.data, w.win_width, BLUE);
	ft_bresenham(53, 4, 4, 53, w.img.data, w.win_width, BLUE);

	ft_bresenham(1, 1, 30, 30, w.img.data, w.win_width, BLUE);
	ft_bresenham(200, 200, 100, 100, w.img.data, w.win_width, BLUE);

	mlx_key_hook(w.win_ptr, ft_key, (void *)&w);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img.img_ptr, 0, 0);

	mlx_loop(w.mlx_ptr);
	return (0);
}	


/*mlx_destroy_image(w.mlx_ptr, w.img.img_ptr);*/
