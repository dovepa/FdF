/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 21:41:42 by dpalombo          #+#    #+#             */
/*   Updated: 2018/09/20 14:59:02 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void ft_ligne(int xa,int ya,int xb,int yb, unsigned int *data, int win_width, int long color) 
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

	data[x * win_width + y] = color;
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
   			data[x * win_width + y] = color;
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
		data[x * win_width + y] = color;
		}
	}
}

void ft_dsqrt(int xa, int ya, int xb,int yb, int xc,int yc, unsigned int *data,int win_width)
{
	ft_ligne(xa, ya, xb, yb, data, win_width, RED);
	ft_ligne(xa, ya, xc, yc, data, win_width, RED);
	return ;
}