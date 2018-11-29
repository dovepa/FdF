/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:18:18 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/29 17:08:05 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_list *ft_parseur(int fd, t_fdf *fdf)
{
	char	*str;
	t_list *list;
	t_list *listc;

	list = NULL;
	fdf->x = 0;
	fdf->y = 0;
	listc = list;
	ft_putendl("\x1b[1m\x1b[32m Parsing... it could take a while\x1b[0m");
	while (get_next_line(fd, &str) > 0)
	{
		if (fdf->x == 0)
			fdf->x = ft_wordlen(str, ' ');
		if ((listc = ft_lstnew((void *)str, (ft_strlen(str) + 1))) == NULL)
			return (NULL);
		fdf->y++;
		ft_lstadd(&list, listc);
		free(str);
	}
	ft_lstrev(&listc);
	return (listc);
}


void	ft_imgdel(t_fdf *fdf)
{
	if (fdf->img != NULL)
	{
		if (fdf->img->img_ptr != NULL)
			mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
		ft_memdel((void **)&fdf->img);
	}
	return ;
}

void	ft_inimg(t_fdf *fdf)
{
	if ((fdf->img = ft_memalloc(sizeof(t_mlximg))) == NULL)
		return ;
	if ((fdf->img->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (ft_imgdel(fdf));
	fdf->img->data = (unsigned int *)mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bpp,\
	 &fdf->img->size_l, &fdf->img->endian);
	return ;
}

t_vector ft_vc(t_vector a, t_fdf *fdf)
{
	double	tmp;
	double	tmp1;

	a.x -= fdf->x / 2;
	a.y -= fdf->y / 2;
	a.z -= (fdf->map->zmin + fdf->map->zmax) / 2;
	a.z *= fdf->arrow->p;
	tmp = a.x * cos(fdf->arrow->x) + a.z * sin(fdf->arrow->x);
	tmp1 = a.z * cos(fdf->arrow->x) - a.x * sin(fdf->arrow->x);
	a.x = tmp;
	a.z = tmp1;
	tmp = a.y * cos(fdf->arrow->y) + a.z * sin(fdf->arrow->y);
	tmp1 = a.z * cos(fdf->arrow->y) - a.y * sin(fdf->arrow->y);
	a.y = tmp;
	a.z = tmp1;
	a.x *= fdf->map->zoom;
	a.y *= fdf->map->zoom;
	a.x += WIN_WIDTH / 2;
	a.y += WIN_HEIGHT / 2;
	return (a);
}

void ft_draw(t_fdf *fdf)
{

	ft_inimg(fdf);

	int x;
	x = 0;
	int y;
	y = 0;

	while (y < fdf->y)
	{
		x = 0;
		while (x < fdf->x)
		{
			if (x + 1 < fdf->x)
				ft_bresenham(fdf, ft_vc(fdf->map->vector[y][x], fdf), ft_vc(fdf->map->vector[y][x + 1], fdf));
			if (y + 1 < fdf->y)
				ft_bresenham(fdf, ft_vc(fdf->map->vector[y][x], fdf), ft_vc(fdf->map->vector[y + 1][x], fdf));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->img_ptr, 0, 0);
	ft_imgdel(fdf);
	return ;
}

t_fdf *ft_init(char *title, t_fdf *fdf)
{
	if ((fdf->mlx_ptr = mlx_init()) == NULL ||	
	(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title)) == NULL ||
	(fdf->arrow = (t_arrow *)ft_memalloc(sizeof(t_arrow))) == NULL)
		return (NULL);
	fdf->arrow->p = 1;
	fdf->arrow->rotate = 0;

	return (fdf);
}