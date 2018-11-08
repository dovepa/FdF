/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:52:23 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/08 16:03:21 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FDF
# define LIB_FDF

#include "libft.h"
#include "mlx.h"
#include <math.h>

/*
**	Map
*/

# define WIN_WIDTH	1000
# define WIN_HEIGHT	800
# define DEFAULTC	0xFF0000

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
# define C_COLOR	8
# define R_COLOR	15

/*
**	hex colors for test (#include "mlx_rgb.c")
**	Structures for use fucking colors in "mlx_rgb.c"
**	color hex to rgb
**	r = ((color >> 16) & 11111111);
**	g = ((color >> 8) & 11111111);
**	b = (color & 11111111);
**	data[y * win_width * 4 + x * 4 + 2] = (char) r;
**	data[y * win_width * 4 + x * 4 + 1] = (char) g;
**	data[y * win_width * 4 + x * 4] = (char) b;
*/

# define WHITE		0xFFFFFF
# define YELLOW		0xFFF00A
# define ORANGE		0xFF9900
# define PINK		0xFF00FF
# define BLUE		0x0000FF
# define RED		0xFF0000

typedef struct		s_col_name
{
  char				*name;
  int				color;
}					t_col_name;

/*
**	Structures
*/

typedef	struct		s_mouse
{
	int				x;
	int				y;
	int				xpast;
	int				ypast;
	int				button;	
}					t_mouse;

typedef	struct		s_vector
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}					t_vector;

typedef	struct		s_map
{
	int				zmin;
	int				zmax;
	int				width;
	int				height;
	int				zoom;
	t_vector		**vector;
	unsigned int	color;
	int				ready;
}					t_map;

typedef	struct		s_mlximg
{
	void			*img_ptr;
	unsigned int	*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_mlximg;

typedef	struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlximg		*img;
	t_mouse			*mouse;
	t_map			*map;
}					t_fdf;

typedef	struct		s_bresenham
{
	int				e;
	int				xi;
	int				yi;
	int				dx;
	int				dy;
	int				i;
}					t_bresenham;


/*
**	Functions
*/
t_fdf *ft_init(char *title, t_fdf *fdf);
void	ft_bresenham(t_fdf *fdf, t_vector v1, t_vector v2);
int		ft_key(int key, t_fdf *fdf);
int		ft_color(t_fdf *fdf);
int		ft_mousemove(int x,int y, t_fdf *fdf);
int		ft_mouseup(int button, int x,int y, t_fdf *fdf);
int		ft_mousedown(int button, int x,int y, t_fdf *fdf);


#endif
