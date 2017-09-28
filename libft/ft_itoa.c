/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:28:09 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/29 11:42:43 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbchar(int n)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = n;
	if (n == 0)
		return (1);
	while (j)
	{
		j /= 10;
		i++;
	}
	if (n < 0)
		return (i + 1);
	return (i);
}

char				*ft_itoa(int n)
{
	int				i;
	unsigned int	j;
	char			*ret;

	i = n;
	j = ft_nbchar(n);
	ret = ft_strnew(j);
	if (ret == NULL)
		return (NULL);
	while (j--)
	{
		if (n < 0)
			ret[j] = '0' + (n % 10) * -1;
		else
			ret[j] = '0' + (n % 10);
		n /= 10;
	}
	if (i < 0)
		ret[0] = '-';
	return (ret);
}
