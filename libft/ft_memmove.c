/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:11:09 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/28 12:00:38 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;
	char		*ret;

	dst2 = dst;
	src2 = src;
	ret = dst;
	if (src2 >= (dst2 + len) || src2 >= dst2)
		while (len)
		{
			*dst2++ = *src2++;
			len--;
		}
	else
	{
		src2 = src2 + len - 1;
		dst2 = dst2 + len - 1;
		while (len)
		{
			*dst2-- = *src2--;
			len--;
		}
	}
	return (ret);
}
