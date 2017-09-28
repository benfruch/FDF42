/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:17:10 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/28 16:48:47 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n_list;

	n_list = (t_list *)malloc(sizeof(t_list));
	if (n_list == NULL)
		return (NULL);
	if (content == NULL)
	{
		n_list->content = NULL;
		n_list->content_size = 0;
	}
	else
	{
		n_list->content = (void *)malloc(sizeof(content_size));
		if (n_list->content == NULL)
			return (NULL);
		ft_memcpy((n_list->content), content, content_size);
		n_list->content_size = content_size;
	}
	n_list->next = NULL;
	return (n_list);
}
