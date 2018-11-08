/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/10/09 16:12:04 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"



// mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);


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
	fdf->img->img_ptr = fdf->img->data = (unsigned int *)mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bpp,\
	 &fdf->img->size_l, &fdf->img->endian);
	return ;
}

void ft_draw(t_fdf *fdf)
{

	ft_inimg(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->img_ptr, 0, 0);
	ft_imgdel(fdf);
	return ;
}

t_fdf *ft_init(char *title, t_fdf *fdf)
{
	if ((fdf->mlx_ptr = mlx_init()) == NULL ||	
	(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title)) == NULL ||
	(fdf->mouse = ft_memalloc(sizeof(t_mouse))) == NULL)
		return (NULL);
	return (fdf);
}

t_list *ft_parseur(int fd, t_fdf *fdf)
{
	char	*str;
	t_list	*list;
	t_list *listc;

	list = NULL;
	listc = list;
	fdf->map->width = 0;	
	fdf->map->height = 0;
	while (get_next_line(fd, &str) > 0)
	{
		if (fdf->map->width == 0)
			fdf->map->width = ft_wordlen(str, ' ');
		if (fdf->map->width != ft_wordlen(str, ' ') || fdf->map->width == 0)
			return (NULL);
		listc = ft_lstnew((void *)str, ft_strlen(str));
		fdf->map->height++;
		ft_lstadd(&list, listc);
		listc = list;
	}
	ft_lstrev(&listc);
	listc = list;
	return (listc);
}
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

int ft_makemap(t_list *list, t_fdf *fdf)
{
	int x;
	int y;
	char **tmp;
	char **tmp2;

	x = 0;
	y = 0;
	if (list == NULL)
		return (1);
	
	if ((fdf->map->vector = ft_memalloc(sizeof(t_vector *) * fdf->map->height)) == NULL)
			return (1);
	while (y < fdf->map->height + 1) 
	{
		if ((fdf->map->vector[y] = ft_memalloc(sizeof(t_vector) * fdf->map->width)) == NULL)
			return (1);
		y++;
	}

	
	if (fdf->map->vector == NULL)
	{
		ft_memdel((void **)&fdf->map);
		return (1);
	}
	
	ft_putendl("abc");
	y = 0;
	while (y < fdf->map->height ) 
	{
		if ((tmp = ft_strsplit(list->content, ' ')) == NULL)
			return (1);
		while (x < fdf->map->width)
		{
			ft_putnbr(x);
			ft_putendl(" ");
			ft_putnbr(fdf->map->width);
			ft_putendl(" ");
			fdf->map->vector[y][x].x = x;
			fdf->map->vector[y][x].y = y;
			if (ft_strchr(tmp[x], ',') == NULL)
			{
				fdf->map->vector[y][x].z = ft_atoi(tmp[x]);
				fdf->map->vector[y][x].color = DEFAULTC;
			}
			else
			{
				if ((tmp2 = ft_strsplit(tmp[x], ',')) == NULL)
					return (1);
				fdf->map->vector[y][x].z = ft_atoi(tmp2[0]);
				fdf->map->vector[y][x].color = ft_atoi(tmp2[1]);
				ft_delsplit(tmp2);				
			}		
			x++;
		}
		list = list->next;
		ft_delsplit(tmp);
		x = 0;
		y++;
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
	if ((fdf = ft_memalloc(sizeof(t_fdf))) == NULL || (fdf->map = ft_memalloc(sizeof(t_map))) == NULL)
		return (1);
	if ((fd = open(argv[1], O_RDONLY)) < 0 || (ft_makemap(ft_parseur(fd, fdf), fdf) == 1))
	{
		ft_strerror("\x1b[1m\x1b[41m  invalid file \x1b[0m");
		return (1);
	}
	close(fd);
	if ((ft_init(ft_strjoin("|--- 42 FdF ---| Map : ", argv[1]), fdf)) == NULL)
		ft_strerror("\x1b[1m\x1b[41m --- Mlx init --- \x1b[0m");
	ft_putendl("\x1b[1m\x1b[32m --- Mlx init --- \x1b[0m");
	

	ft_draw(fdf);
	
	mlx_key_hook(fdf->win_ptr, ft_key, (void *)&fdf);
	mlx_hook(fdf->win_ptr, 6, 0, ft_mousemove, (void *)&fdf);
	mlx_hook(fdf->win_ptr, 4, 0, ft_mousedown, (void *)&fdf);
	mlx_hook(fdf->win_ptr, 5, 0, ft_mouseup, (void *)&fdf);
	
	
	
	mlx_loop(fdf->mlx_ptr);

	return (0);
}	


/*mlx_destroy_image(w.mlx_ptimg->img_ptr);*/
