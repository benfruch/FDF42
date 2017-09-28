/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:03:43 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/24 14:03:32 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		if (s1[i] == c1)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
