/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/09/20 14:59:11 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	main(int argc, char **argv)
{
	t_windows w;
	
	w.win_width = 800;
	w.win_height = 600;

	if (argc != 2)
	{
		ft_usage("./fdf exemple_of_maps");
		return (1);
	}
	w.title = ft_strjoin("|--- 42 FdF ---| Map : ", argv[1]);
	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.win_width, w.win_height, w.title);
	w.img.img_ptr = mlx_new_image(w.mlx_ptr, w.win_width, w.win_height);
	w.img.data = (unsigned int *)mlx_get_data_addr(w.img.img_ptr, &w.img.bpp,
		&w.img.size_l, &w.img.endian);
	
	mlx_key_hook(w.win_ptr, ft_how_to, (void*)&w);
	
	
	ft_dsqrt(300, 300, 200, 200, 300, 200, w.img.data, w.win_width);

	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img.img_ptr, 0, 0);
	
	mlx_loop(w.mlx_ptr);
	return (0);
}	


/*mlx_destroy_image(w.mlx_ptr, w.img.img_ptr);*/
