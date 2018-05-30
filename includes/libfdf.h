/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:52:23 by dpalombo          #+#    #+#             */
/*   Updated: 2018/05/30 15:58:26 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FDF
# define LIB_FDF

#include "libft.h"
#include "mlx.h"
#include <math.h>

typedef	struct		s_mlximg
{
	void			*img_ptr;
	unsigned int	*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_mlximg;

typedef	struct		s_windows
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlximg		img;
}					t_windows;

#endif
