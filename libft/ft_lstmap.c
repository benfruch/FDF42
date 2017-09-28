/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:30:10 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/28 16:30:33 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_siz_map(t_list *lst)
{
	t_list	*temp;
	size_t	len;

	temp = lst;
	len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;
	size_t	len;

	if (!lst || !f)
		return (NULL);
	len = ft_siz_map(lst);
	new = NULL;
	temp = NULL;
	if ((temp = (t_list *)malloc((sizeof(t_list) * len))))
	{
		new = f(ft_lstnew(lst->content, lst->content_size));
		temp = new;
		lst = lst->next;
		while (lst)
		{
			temp->next = f(ft_lstnew(lst->content, lst->content_size));
			temp = temp->next;
			lst = lst->next;
		}
	}
	return (new);
}
