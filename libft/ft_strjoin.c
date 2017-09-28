/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:12:07 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/28 10:25:49 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		j;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	k = 0;
	while (s1[k] != '\0')
	{
		s3[k] = s1[k];
		k++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[k] = s2[j];
		k++;
		j++;
	}
	s3[k] = '\0';
	return (s3);
}
