/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/30 16:24:22 by dpalombo         ###   ########.fr       */
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

static int ft_makevecx(int x, int y, t_fdf *fdf, char **tmp)
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

static int ft_makevec(t_fdf *fdf, t_list *listc)
{
	int x;
	int y;
	char **tmp;

	y = -1;
	x = -1;
	while (++y < fdf->y ) 
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

int ft_makemap(t_list *list, t_fdf *fdf)
{
	int x;
	int y;
	t_list *listc;

	listc = list;
	x = 0;
	y = 0;
	if ((list == NULL) || ((fdf->map->vector = ft_memalloc(sizeof(t_vector *) * fdf->y)) == NULL))
			return (1);
	while (x < fdf->y)
		if (!(fdf->map->vector[x++] = ft_memalloc(sizeof(t_vector) * fdf->x)))
			return (1);
	if (ft_makevec(fdf, listc) == 1)
		return (1);	
	ft_findz(fdf);
	return (0);	
}

int ft_exit(t_fdf *fdf)
{
	(void)fdf;
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(EXIT_SUCCESS);
}

int ft_cmdkey(int key, t_fdf *fdf)
{
	if (key == MORE_KEY || key == LESS_KEY)
	{
		if (fdf->map->zoom <= 1 )
			fdf->map->zoom = 2;
		fdf->map->zoom += 2 * (key % 10) - 17;
	}
	if (key == UP_KEY || key == DOWN_KEY)
		fdf->arrow->y += (double)((2 * (key % 120) - 11) / 10.0);
	if (key == RIGHT_KEY || key == LEFT_KEY)
		fdf->arrow->x += (double)((2 * (key % 120) - 7) / 10.0);
	if (key == Q_KEY || key == W_KEY)
		fdf->arrow->p += (double)((2 * (key % 10) - 5) / 50.0);
	if (key == MORE_KEY || key == LESS_KEY || key == UP_KEY || key == DOWN_KEY ||\
	key == RIGHT_KEY || key == LEFT_KEY || key == Q_KEY || key == W_KEY)
		ft_draw(fdf);
	return (0);
}

t_fdf *ft_infdf(t_fdf *fdf)
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

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		fd;
	char	*str1;
	t_list	*list;
	
	list = NULL;
	fdf = NULL;
	if (argc != 2)
		return (ft_usage("\x1b[1m\x1b[41m ./fdf exemple_of_maps \x1b[0m"));
	if (((fdf = ft_infdf(fdf)) == NULL) || ((fd = open(argv[1], O_RDONLY)) < 0) || \
	((list = ft_parseur(fd, fdf)) == NULL) || (ft_makemap(list,fdf) == 1))
		return (ft_strerror("\x1b[1m\x1b[41m  invalid file \x1b[0m"));
	close(fd);
	if ((ft_init((str1 = ft_strjoin("42 FdF : ", argv[1])), fdf)) == NULL)
		return (ft_strerror("\x1b[1m\x1b[41m  --- Mlx init error --- \x1b[0m"));
	ft_putendl("\x1b[1m\x1b[32m --- Mlx init --- \x1b[0m");
	ft_draw(fdf);		
	mlx_key_hook(fdf->win_ptr, ft_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, ft_exit, fdf);
	mlx_hook(fdf->win_ptr, 2, 0, ft_cmdkey, fdf);	
	mlx_loop(fdf->mlx_ptr);
	return (0);
}	
