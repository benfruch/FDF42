/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:30:45 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/28 16:31:19 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = ft_strlen(dst);
	j = 0;
	k = ft_strlen(src);
	if (size <= i)
		return (size + k);
	while (src[j] && i < (size - j - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (k + i);
}
