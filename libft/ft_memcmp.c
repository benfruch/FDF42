/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:11:24 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/25 12:53:10 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *t1;
	unsigned char *t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	if (!s1 && !s2 && !n)
		return (0);
	if (!n)
		return (0);
	while (n--)
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		if (n)
		{
			t1++;
			t2++;
		}
	}
	return (*t1 - *t2);
}
