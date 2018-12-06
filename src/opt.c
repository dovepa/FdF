/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:24:59 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/06 14:49:26 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_delsplit(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_memdel((void *)&s[i]);
		i++;
	}
	ft_memdel((void *)&s);
}

void	ft_findz(t_fdf *fdf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < fdf->y)
	{
		x = 0;
		while (x < fdf->x)
		{
			if (fdf->map->vector[y][x].z < fdf->map->zmin)
				fdf->map->zmin = fdf->map->vector[y][x].z;
			if (fdf->map->vector[y][x].z > fdf->map->zmax)
				fdf->map->zmax = fdf->map->vector[y][x].z;
			x++;
		}
		y++;
	}
	return ;
}

int		ft_makemap(t_list *list, t_fdf *fdf)
{
	int		x;
	int		y;
	t_list	*listc;

	listc = list;
	x = 0;
	y = 0;
	if ((list == NULL) || ((fdf->map->vector = \
	ft_memalloc(sizeof(t_vector *) * fdf->y)) == NULL))
		return (1);
	while (x < fdf->y)
		if (!(fdf->map->vector[x++] = ft_memalloc(sizeof(t_vector) * fdf->x)))
			return (1);
	if (ft_makevec(fdf, listc) == 1)
		return (1);
	ft_findz(fdf);
	return (0);
}

int		ft_cmdkey(int key, t_fdf *fdf)
{
	if (key == MORE_KEY || key == LESS_KEY)
	{
		if (fdf->map->zoom <= 1)
			fdf->map->zoom = 2;
		fdf->map->zoom += 2 * (key % 10) - 17;
	}
	if (key == UP_KEY || key == DOWN_KEY)
		fdf->arrow->y += (double)((2 * (key % 120) - 11) / 10.0);
	if (key == RIGHT_KEY || key == LEFT_KEY)
		fdf->arrow->x += (double)((2 * (key % 120) - 7) / 10.0);
	if (key == Q_KEY || key == W_KEY)
		fdf->arrow->p += (double)((2 * (key % 10) - 5) / 50.0);
	if (key == MORE_KEY || key == LESS_KEY || key == UP_KEY || key == DOWN_KEY\
	|| key == RIGHT_KEY || key == LEFT_KEY || key == Q_KEY || key == W_KEY)
		ft_draw(fdf);
	return (0);
}
