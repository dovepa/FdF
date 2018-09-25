/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:52:23 by dpalombo          #+#    #+#             */
/*   Updated: 2018/09/25 14:13:22 by dpalombo         ###   ########.fr       */
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

# define ESC_KEY	53
# define UP_KEY		126
# define DOWN_KEY	125
# define RIGHT_KEY	124
# define LEFT_KEY	123
# define MORE_KEY	69
# define LESS_KEY	78

/*
**	hex colors
*/

# define WHITE		0xFFFFFF
# define GREY		0xCCCCCC
# define ORANGE		0xFF9900
# define PINK		0xFF00FF
# define BLUE		0x0000FF
# define RED		0xFF0000

/*
**	Structures
*/

typedef	struct		s_mlximg
{
	void			*img_ptr;
	char			*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_mlximg;

typedef	struct		s_windows
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	char			*title;
	t_mlximg		img;
}					t_windows;

/*
**	Functions
*/

void ft_pixel(int x,int y, char *data, int win_width, unsigned int color);
void ft_bresenham(int x1, int y1, int x2, int y2, char *data, int win_width, unsigned int color);
int ft_key(int key, t_windows *windows);

#endif
