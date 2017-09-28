/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:50:53 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/28 17:02:48 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[j] != '\0')
	{
		str[j] = f(s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
