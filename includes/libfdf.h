/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:52:23 by dpalombo          #+#    #+#             */
/*   Updated: 2018/09/20 14:52:19 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FDF
# define LIB_FDF

#include "libft.h"
#include "mlx.h"
#include <math.h>

/*
**	Keyboard
*/

# define ESC_KEY	0x35
# define UP_KEY		0x7E
# define DOWN_KEY	0x7D
# define RIGHT_KEY	0x7C
# define LEFT_KEY	0x7B
# define MORE_KEY	0x45
# define LESS_KEY	0x4E

/*
**	find this in /System/Library/Frameworks/Carbon.framework/Versions/A/ \
**	Frameworks/HIToolbox.framework/Versions/A/Headers/Events.h
*/

/*
**	hex colors
*/

# define WHITE		0xFFFFFF
# define GREY		0xCCCCCC
# define ORANGE		0xFF9900
# define PINK		0xFF00FF
# define BLUE		0x0000FF
# define RED		0xFF0000

typedef	struct		s_mlximg
{
	void			*img_ptr;
	unsigned int	*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_mlximg;

typedef	struct		s_map
{
	int				x;
	int				y;
	int				z;
	int				scale;
	int				focus;
}					t_map;

typedef	struct		s_windows
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	char			*title;
	int				center_x;
	int				center_y;
	t_mlximg		img;
	t_map			map;
}					t_windows;

int		ft_how_to(int key, t_windows *windows);
void	ft_dsqrt(int xa, int ya, int xb,int yb, int xc,int yc, unsigned int *data,int win_width);

#endif
