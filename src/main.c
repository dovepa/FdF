/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/06 14:45:35 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static int	ft_makevecx(int x, int y, t_fdf *fdf, char **tmp)
{
	char **tmp2;

	fdf->map->vector[y][x].x = (double)x;
	fdf->map->vector[y][x].y = (double)y;
	if (ft_strchr(tmp[x], ',') == NULL)
	{
		fdf->map->vector[y][x].z = (double)ft_atoi(tmp[x]);
		fdf->map->vector[y][x].color = DEFAULTC;
	}
	else
	{
		if ((tmp2 = ft_strsplit(tmp[x], ',')) == NULL)
			return (1);
		fdf->map->vector[y][x].z = (double)ft_atoi(tmp2[0]);
		fdf->map->vector[y][x].color = ft_atohexp(tmp2[1]);
		ft_delsplit(tmp2);
	}
	return (0);
}

int			ft_makevec(t_fdf *fdf, t_list *listc)
{
	int		x;
	int		y;
	char	**tmp;

	y = -1;
	x = -1;
	while (++y < fdf->y)
	{
		if ((tmp = ft_strsplit(listc->content, ' ')) == NULL)
			return (1);
		while (++x < fdf->x)
			if (ft_makevecx(x, y, fdf, tmp) == 1)
				return (1);
		listc = listc->next;
		ft_delsplit(tmp);
		x = -1;
	}
	return (0);
}

t_fdf		*ft_infdf(t_fdf *fdf)
{
	if ((fdf = ft_memalloc(sizeof(t_fdf))) == NULL)
		return (NULL);
	if ((fdf->map = ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	fdf->map->zmin = 0;
	fdf->map->zmax = 0;
	fdf->map->zoom = 1;
	fdf->map->ready = 0;
	fdf->map->cn = 0;
	fdf->map->color = DEFAULTC;
	return (fdf);
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		fd;
	t_list	*list;

	list = NULL;
	fdf = NULL;
	if (argc != 2)
		return (ft_usage("\x1b[1m\x1b[41m ./fdf exemple_of_maps \x1b[0m"));
	fdf = ft_infdf(fdf);
	fd = open(argv[1], O_RDONLY);
	list = ft_parseur(fd, fdf);
	if ((fdf == NULL) || (fd < 0) || (list == NULL) || \
	(ft_makemap(list, fdf) == 1))
		return (ft_strerror("\x1b[1m\x1b[41m  invalid file \x1b[0m"));
	close(fd);
	fdf->title = ft_strjoin("42 FdF : ", argv[1]);
	if (ft_init(fdf->title, fdf) == 1)
		return (ft_strerror("\x1b[1m\x1b[41m  --- Mlx init error --- \x1b[0m"));
	ft_putendl("\x1b[1m\x1b[32m --- Mlx init --- \x1b[0m");
	ft_draw(fdf);
	mlx_key_hook(fdf->win_ptr, ft_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, ft_exit, fdf);
	mlx_hook(fdf->win_ptr, 2, 0, ft_cmdkey, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
