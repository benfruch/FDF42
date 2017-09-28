/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:38:41 by bfruchar          #+#    #+#             */
/*   Updated: 2017/09/28 10:06:21 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_color_map(int keycode, t_env *e)
{
	if (keycode == 256 && e->red + 10 < 255)
		e->red = e->red + 10;
	if (keycode == 261 && e->green + 10 < 255)
		e->green = e->green + 10;
	if (keycode == 259 && e->blue + 10 < 255)
		e->blue = e->blue + 10;
	if (keycode == 6)
		e->red = 000;
	if (keycode == 7)
		e->green = 000;
	if (keycode == 8)
		e->blue = 000;
}

void	ft_expo_x_y(int keycode, t_env *e)
{
	if (keycode == 125)
		e->expose_y += 0.02;
	if (keycode == 126)
		e->expose_y -= 0.02;
}

int		my_key_funct(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		ft_expo_x_y(keycode, e);
	if (keycode == 256 || keycode == 261 || keycode == 259
			|| keycode == 6 || keycode == 7 || keycode == 8)
		ft_color_map(keycode, e);
	if (keycode == 258)
		e->zoom = e->zoom + 1;
	if (keycode == 269 && e->zoom - 1 > 0)
		e->zoom = e->zoom - 1;
	if (keycode == 69 && e->zoom_d + 2 < 15)
		e->zoom_d = e->zoom_d + 2;
	if (keycode == 78 && e->zoom_d - 2 > -15)
		e->zoom_d = e->zoom_d - 2;
	return (0);
}
