/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:35:48 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/24 15:54:08 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizetofind(char const *s)
{
	int i;
	int j;
	int k;

	i = 0;
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	k = i;
	if (s[i] != '\0')
	{
		i = j - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			k++;
		}
	}
	return (j - k);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*s2;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	k = ft_sizetofind(s);
	s2 = (char *)malloc(sizeof(char) * (k + 1));
	if (s2 == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < k)
	{
		s2[j] = s[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
