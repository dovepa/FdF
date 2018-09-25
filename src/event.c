/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:12:15 by dpalombo          #+#    #+#             */
/*   Updated: 2018/09/25 14:12:53 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int ft_key(int key, t_windows *windows)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window((*windows).mlx_ptr, (*windows).win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
