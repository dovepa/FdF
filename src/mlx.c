/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:14:53 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/06 14:51:16 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int		ft_imgdel(t_fdf *fdf)
{
	if (fdf->img != NULL)
	{
		if (fdf->img->img_ptr != NULL)
			mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
		ft_memdel((void **)&fdf->img);
	}
	return (1);
}

int		ft_inimg(t_fdf *fdf)
{
	if ((fdf->img = ft_memalloc(sizeof(t_mlximg))) == NULL)
		return (1);
	if ((fdf->img->img_ptr = \
	mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (ft_imgdel(fdf));
	fdf->img->data = (unsigned int *)mlx_get_data_addr(fdf->img->img_ptr, \
	&fdf->img->bpp, &fdf->img->size_l, &fdf->img->endian);
	return (0);
}

int		ft_init(char *title, t_fdf *fdf)
{
	if ((fdf->mlx_ptr = mlx_init()) == NULL || \
	(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, \
	WIN_WIDTH, WIN_HEIGHT, title)) == NULL || \
	(fdf->arrow = (t_arrow *)ft_memalloc(sizeof(t_arrow))) == NULL)
		return (1);
	fdf->arrow->p = 1;
	fdf->arrow->rotate = 0;
	fdf->arrow->x = DEFAULTX;
	fdf->arrow->y = DEFAULTY;
	return (0);
}

int		ft_exit(t_fdf *fdf)
{
	(void)fdf;
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
