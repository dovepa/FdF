/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/29 15:09:58 by dpalombo         ###   ########.fr       */
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

int ft_makemap(t_list *list, t_fdf *fdf)
{
	int x;
	int y;
	char **tmp;
	char **tmp2;
	t_list *listc;

	x = 0;
	listc = list;
	y = 0;
	if (list == NULL)
		return (1);
	
	if (!(fdf->map->vector = ft_memalloc(sizeof(t_vector *) * fdf->y)))
			return (1);

	while (x < fdf->y)
		if (!(fdf->map->vector[x++] = ft_memalloc(sizeof(t_vector) * fdf->x)))
			return (1);

	if (fdf->map->vector == NULL)
	{
		ft_memdel((void **)&fdf->map);
		return (1);
	}
	y = 0;
	x = 0;
	while (y < fdf->y ) 
	{
		if ((tmp = ft_strsplit(listc->content, ' ')) == NULL)
			return (1);
		while (x < fdf->x)
		{
		
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
			x++;
		}
		listc = listc->next;
		ft_delsplit(tmp);
		x = 0;
		y++;
	}
	ft_findz(fdf);
	return (0);	
}

int ft_exit(t_fdf *fdf)
{
	(void)fdf;
	//free(fdf);
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
		ft_draw(fdf);
	}
	if (key == UP_KEY || key == DOWN_KEY)
	{
		fdf->arrow->y += (double)((2 * (key % 120) - 11) / 10.0);
		ft_draw(fdf);
	}
	if (key == RIGHT_KEY || key == LEFT_KEY)
	{
		fdf->arrow->x += (double)((2 * (key % 120) - 7) / 10.0);
		ft_draw(fdf);
	}
	if (key == Q_KEY || key == W_KEY)
	{
		fdf->arrow->p += (double)((2 * (key % 10) - 5) / 50.0);
		ft_draw(fdf);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int fd;

	if (argc != 2)
	{
		ft_usage("\x1b[1m\x1b[41m ./fdf exemple_of_maps \x1b[0m");
		return (1);
	}
	if ((fdf = ft_memalloc(sizeof(t_fdf))) == NULL)
		return (1);
	if ((fdf->map = ft_memalloc(sizeof(t_map))) == NULL)
		return (1);
	fdf->map->zmin = 0;
	fdf->map->zmax = 0;
	fdf->map->zoom = 25;
	fdf->map->ready = 0;
	fdf->map->cn = 0;
	fdf->map->color = DEFAULTC;


	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_strerror("\x1b[1m\x1b[41m  invalid file \x1b[0m");
		return (1);
	}
	t_list *list;
	list = NULL;
	list = ft_parseur(fd, fdf);
	
	
	ft_makemap(list, fdf);
	close(fd);
	char *str1 = ft_strjoin("|--- 42 FdF ---| Map : ", argv[1]);
	if ((ft_init(str1, fdf)) == NULL)
		ft_strerror("\x1b[1m\x1b[41m --- Mlx init --- \x1b[0m");
	ft_putendl("\x1b[1m\x1b[32m --- Mlx init --- \x1b[0m");
	fdf->arrow->x = DEFAULTX;
	fdf->arrow->y = DEFAULTY;

	ft_draw(fdf);		

	mlx_key_hook(fdf->win_ptr, ft_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, ft_exit, fdf);
	mlx_hook(fdf->win_ptr, 2, 0, ft_cmdkey, fdf);	
	mlx_loop(fdf->mlx_ptr);

	return (0);
}	
