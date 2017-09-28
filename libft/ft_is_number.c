/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:21:44 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/28 15:24:34 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_number(char *str)
{
	unsigned int i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
