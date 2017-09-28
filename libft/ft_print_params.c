/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:50:04 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/28 13:59:09 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_params(int argc, char **argv)
{
	int n;
	int i;

	n = 1;
	i = argc;
	while (argv[n] != '\0')
	{
		ft_putstr(argv[n]);
		ft_putchar('\n');
		n++;
	}
	return ;
}
