/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:29:51 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/28 10:29:31 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!*little)
		return ((char *)big);
	k = ft_strlen(little);
	while (big[i] && (i + k - 1) < len)
	{
		if (big[i] == *little)
		{
			j = 0;
			while (big[i + j] == little[j] && (i + j) < len)
			{
				if (little[j + 1] == '\0' || (i + j) == len - 1)
					return ((char *)big + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
