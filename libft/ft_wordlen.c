/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:45:47 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/08 14:28:59 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_wordlen(char *str, char sep)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sep && i > 0 && str[i-1] != sep)
		{
			while (str[i] == sep)
				i++;
			x++;
		}
		i++;
	}
	if (i > 0)
		x++;
	return (x);
}
