/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:48:19 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/21 18:48:42 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*new;

	new = ft_memalloc(content_size + 1);
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new = NULL;
		content_size = 0;
	}
	else
		ft_memcpy(new, content, content_size);
	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = new;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
