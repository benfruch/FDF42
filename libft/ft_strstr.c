/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:29:04 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/24 15:49:27 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_string_t(const char *big, const char *little, int i)
{
	int j;

	j = 0;
	while (big[i] == little[j] && little[j] != '\0')
	{
		i++;
		j++;
	}
	if (little[j] == '\0')
		return (1);
	return (0);
}

char			*ft_strstr(const char *big, const char *little)
{
	int i;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		if (ft_string_t(big, little, i) == 1)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
