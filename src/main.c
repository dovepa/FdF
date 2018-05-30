/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/05/17 11:00:34 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;

	if (argc != 2)
	{
		ft_usage("./fdf exemple_of_maps");
		return (1);
	}
	mlx_ptr = mlx_init();
	mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, ft_strjoin("|--- 42 FdF ---| Map : ", argv[1]));
	mlx_loop(mlx_ptr);
	return (0);
}
