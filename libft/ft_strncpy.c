/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 08:30:13 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/24 14:19:07 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t lan;
	size_t i;

	lan = 0;
	i = ft_strlen(src);
	while (lan < len)
	{
		if (lan > i)
			dst[lan] = '\0';
		else
			dst[lan] = src[lan];
		lan++;
	}
	return (dst);
}
