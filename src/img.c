/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:18:18 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/06 14:24:21 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_list		*ft_parseur(int fd, t_fdf *fdf)
{
	char	*str;
	t_list	*list;
	t_list	*listc;

	list = NULL;
	fdf->x = __INT_MAX__;
	fdf->y = 0;
	listc = list;
	ft_putendl("\x1b[1m\x1b[32m Parsing... it could take a while\x1b[0m");
	while (get_next_line(fd, &str) > 0)
	{
		if (fdf->x > ft_wordlen(str, ' '))
			fdf->x = ft_wordlen(str, ' ');
		if ((listc = ft_lstnew((void *)str, (ft_strlen(str) + 1))) == NULL)
			return (NULL);
		fdf->y++;
		ft_lstadd(&list, listc);
		free(str);
	}
	if ((fdf->x == __INT_MAX__) || (fdf->x <= 0))
		return (NULL);
	ft_lstrev(&listc);
	return (listc);
}

t_vector	ft_vc(t_vector a, t_fdf *fdf)
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

void		ft_draw(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	if (ft_inimg(fdf) == 1)
		return ;
	while (y < fdf->y)
	{
		x = 0;
		while (x < fdf->x)
		{
			if (x + 1 < fdf->x)
				ft_bresenham(fdf, ft_vc(fdf->map->vector[y][x], fdf), \
				ft_vc(fdf->map->vector[y][x + 1], fdf));
			if (y + 1 < fdf->y)
				ft_bresenham(fdf, ft_vc(fdf->map->vector[y][x], fdf), \
				ft_vc(fdf->map->vector[y + 1][x], fdf));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, \
	fdf->win_ptr, fdf->img->img_ptr, 0, 0);
	ft_imgdel(fdf);
	return ;
}
