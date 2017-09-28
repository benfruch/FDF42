/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:13:41 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/24 14:07:40 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	j;

	i = 0;
	j = (unsigned char)c;
	str = (unsigned char *)b;
	while (len > i)
	{
		str[i] = j;
		i++;
	}
	return (b);
}
