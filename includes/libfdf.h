/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:52:23 by dpalombo          #+#    #+#             */
/*   Updated: 2018/05/10 16:22:24 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FDF
# define LIB_FDF

#include "libft.h"
#include "mlx.h"
#include <math.h>

int ft_line2(int xi, int yi, int xf, int yf, void **mlx_ptr, void **win_ptr, int color);
void ft_ligne(int xi,int yi,int xf,int yf, void *mlx_ptr, void *win_ptr, int color);

typedef	struct		s_dot
{
	int				xa;
	int				ya;
	int				xb;
	int				yb;
	int				xc;
	int				yc;
	int				z;
	struct s_list	*next;
}					t_dot;

typedef	struct		s_windows
{
	void			*mlp_ptr;
	void			*win_ptr;
}					t_windows;

#endif
