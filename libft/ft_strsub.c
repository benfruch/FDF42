/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:56:22 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/24 14:20:11 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}
