/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 21:41:42 by dpalombo          #+#    #+#             */
/*   Updated: 2018/05/17 10:51:53 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_ligne(int xa,int ya,int xb,int yb, void *mlx_ptr, void *win_ptr, int color) 
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

	mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
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
   			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
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
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		}
	}
}

void ft_dsqrt(int xa, int ya, int xb,int yb, int xc,int yc, void *mlx_ptr, void *win_ptr, int color)
{
	ft_ligne(xa, ya, xb, yb, mlx_ptr, win_ptr, color);
	ft_ligne(xa, ya, xc, yc, mlx_ptr, win_ptr, color);
	return ;
}

