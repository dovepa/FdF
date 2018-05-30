/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/05/30 16:34:13 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include "stdio.h"

void ft_ligne(int xa,int ya,int xb,int yb, unsigned int *data, int win_width) 
{
	int dx;
	int	dy;
	int	i;
	int xanc;
	int	yanc;
	int	cumul;
	int	x;
	int	y;
	
	x = xa ;
	y = ya ;
	dx = xb - xa ;
	dy = yb - ya ;
	xanc = ( dx > 0 ) ? 1 : -1 ;
	yanc = ( dy > 0 ) ? 1 : -1 ;

	dx = dx < 0 ? dx * -1 : dx;
	dy = dy < 0 ? dy * -1 : dy;

	data[x * win_width + y] = 0xFFFFFF;
	if ( dx > dy )
	{
		cumul = dx / 2 ;
  		for ( i = 1 ; i <= dx ; i++ )
		{
   			x += xanc ;
   			cumul += dy ;
   			if ( cumul >= dx )
			{
   				cumul -= dx ;
   				y += yanc ;
			}
   			data[x * win_width + y] = 0xFFFFFF;
		}
	}
    else
	{
		cumul = dy / 2 ;
		for ( i = 1 ; i <= dy ; i++ )
		{
   			y += yanc ;
		    cumul += dx ;
		    if ( cumul >= dy )
			{
		        cumul -= dy ;
		        x += xanc ;
			}
		data[x * win_width + y] = 0xFFFFFF;
		}
	}
}

void ft_dsqrt(int xa, int ya, int xb,int yb, int xc,int yc, unsigned int *data,int win_width)
{
	ft_ligne(xa, ya, xb, yb, data, win_width);
	ft_ligne(xa, ya, xc, yc, data, win_width);
	return ;
}


int	main(int argc, char **argv)
{
	t_windows windows;
	int win_width = 800;
	int win_height = 600;

	
	if (argc != 2)
	{
		ft_usage("./fdf exemple_of_maps");
		return (1);
	}
	windows.mlx_ptr = mlx_init();
	windows.win_ptr = mlx_new_window(windows.mlx_ptr, win_width, win_height, ft_strjoin("|--- 42 FdF ---| Map : ", argv[1]));
	windows.img.img_ptr = mlx_new_image(windows.mlx_ptr, win_width, win_height);
	windows.img.data = (unsigned int *)mlx_get_data_addr(windows.img.img_ptr, &windows.img.bpp, &windows.img.size_l,
		&windows.img.endian);

	ft_dsqrt(10, 10, 200, 200, 10, 200, windows.img.data, win_width);
	
	mlx_put_image_to_window(windows.mlx_ptr, windows.win_ptr, windows.img.img_ptr, 0, 0);
	mlx_loop(windows.mlx_ptr);
	return (0);
}	


/*mlx_destroy_image(windows.mlx_ptr, windows.img.img_ptr);*/
