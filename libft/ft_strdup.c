/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:39:04 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/24 14:12:17 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	cp = (char*)malloc(sizeof(char) * (j + 1));
	if (!cp)
		return (NULL);
	while (j > i)
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
