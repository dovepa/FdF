/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:52:23 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/30 16:27:29 by dpalombo         ###   ########.fr       */
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
# define DEFAULTC	0xFFFFFF
# define DEFAULTX	45.0
# define DEFAULTY	25.0

/*
**	Keyboard and Colors
*/

# define ESC_KEY	53
# define UP_KEY		126
# define DOWN_KEY	125
# define RIGHT_KEY	124
# define LEFT_KEY	123
# define MORE_KEY	69
# define LESS_KEY	78
# define C_COLOR	8
# define R_ROTATE	15
# define KING		40
# define Q_KEY		12
# define W_KEY		13
# define WHITE		0xFFFFFF
# define YELLOW		0xFFF00A
# define ORANGE		0xFF9900
# define PINK		0xFF00FF
# define BLUE		0x0000FF
# define RED		0xFF0000

/*
**	Structures
*/

typedef	struct		s_arrow
{
	double			x;
	double			y;
	double			p;
	int				rotate;
}					t_arrow;

typedef	struct		s_vector
{
	double				x;
	double			y;
	double			z;
	unsigned int	color;
}					t_vector;

typedef	struct		s_map
{
	int				zmin;
	int				zmax;
	int				cn;
	t_vector		**vector;
	unsigned int	color;
	int				ready;
	int				zoom;
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
	int				x;
	int				y;
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlximg		*img;
	t_map			*map;
	t_arrow			*arrow;
}					t_fdf;

typedef	struct		s_bresenham
{
	int				e;
	t_vector		vec[2];
	int				xi;
	int				yi;
	double			dx;
	double			dy;
	int				i;
}				t_bresenham;


/*
**	Functions
*/

void		ft_delsplit(char **s);
void		ft_findz(t_fdf *fdf);
int			ft_makemap(t_list *list, t_fdf *fdf);
int			ft_exit(t_fdf *fdf);
int			ft_cmdkey(int key, t_fdf *fdf);
t_fdf		*ft_infdf(t_fdf *fdf);
int			ft_key(int key, t_fdf *fdf);
void		ft_bresenham(t_fdf *fdf, t_vector v1, t_vector v2);
t_list		*ft_parseur(int fd, t_fdf *fdf);
int			ft_imgdel(t_fdf *fdf);
int			ft_inimg(t_fdf *fdf);
t_vector	ft_vc(t_vector a, t_fdf *fdf);
void		ft_draw(t_fdf *fdf);
t_fdf		*ft_init(char *title, t_fdf *fdf);

#endif
