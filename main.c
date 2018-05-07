/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/05/06 18:12:55 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"

int	main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "|--- 42 FdF ---|");
	mlx_pixel_put(mlx_ptr, win_ptr, 11, 11, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 10, 10, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 12, 12, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 13, 13, 0xFF0000);
	int  y = 100;
	int x;
   while (y < 200)
   {
       x = 100;
       while (x < 200)
       {
           mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
           x++;
       }
       y++;
   }

	mlx_loop(mlx_ptr);
	return (0);
}
