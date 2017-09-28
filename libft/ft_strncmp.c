/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:02:20 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/28 12:17:29 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t m;
	size_t o;

	m = 0;
	if (n == 0)
		return (0);
	o = n - 1;
	while (n && s1[m] != '\0' && m < o)
	{
		if ((unsigned char)s1[m] != (unsigned char)s2[m])
			return ((unsigned char)s1[m] - (unsigned char)s2[m]);
		m++;
		n--;
	}
	return ((unsigned char)s1[m] - (unsigned char)s2[m]);
}
