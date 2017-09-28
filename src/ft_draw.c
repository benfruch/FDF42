/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:13:42 by bfruchar          #+#    #+#             */
/*   Updated: 2017/09/28 09:09:37 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		expose_hook(t_env *e)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_print_map(e, x, y);
	return (0);
}

void	ft_new_image(t_env *e)
{
	int	bpp;
	int	s_l;
	int	endian;

	e->img_ptr = mlx_new_image(e->mlx, SIZE_X, SIZE_Y);
	e->data = mlx_get_data_addr(e->img_ptr, &bpp, &s_l, &endian);
}
