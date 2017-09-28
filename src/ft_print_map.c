/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:29:20 by bfruchar          #+#    #+#             */
/*   Updated: 2017/09/28 14:12:52 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_pixel_in(t_env *e, int y, int x)
{
	if (x > 0 && y > 0 && x < SIZE_X && y < SIZE_Y)
	{
		e->data[(x * 4) + (y * SIZE_X * 4)] = e->red;
		e->data[(x * 4) + (y * SIZE_X * 4) + 1] = e->green;
		e->data[(x * 4) + (y * SIZE_X * 4) + 2] = e->blue;
	}
}

void	ft_lines(t_env *e)
{
	double dx;
	double dy;
	double x;
	double y;
	double temp;

	x = e->x_start;
	y = e->y_start;
	dx = e->x_end - e->x_start;
	dy = e->y_end - e->y_start;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		ft_put_pixel_in(e, y, x);
		x += dx;
		y += dy;
		temp--;
	}
}

void	ft_coord_x(t_env *e, int x, int y)
{
	int	xt;
	int	yt;

	xt = x - e->x_max / 2;
	yt = y - e->y_max / 2;
	e->x_start = e->expose_x * (xt - yt) * e->zoom;
	e->y_start = e->expose_y * (xt + yt) * e->zoom;
	e->y_start -= e->map[y][x] * e->zoom_d;
	e->x_end = e->expose_x * ((xt + 1) - yt) * e->zoom;
	e->y_end = e->expose_y * ((xt + 1) + yt) * e->zoom;
	e->y_end -= e->map[y][x + 1] * e->zoom_d;
	e->x_start += SIZE_X / 2;
	e->x_end += SIZE_X / 2;
	e->y_start += SIZE_Y / 2;
	e->y_end += SIZE_Y / 2;
}

void	ft_coord_y(t_env *e, int x, int y)
{
	int	xt;
	int	yt;

	xt = x - e->x_max / 2;
	yt = y - e->y_max / 2;
	e->x_start = e->expose_x * (xt - yt) * e->zoom;
	e->y_start = e->expose_y * (xt + yt) * e->zoom;
	e->y_start -= e->map[y][x] * e->zoom_d;
	e->x_end = e->expose_x * (xt - (yt + 1)) * e->zoom;
	e->y_end = e->expose_y * (xt + (yt + 1)) * e->zoom;
	e->y_end -= e->map[y + 1][x] * e->zoom_d;
	e->x_start += SIZE_X / 2;
	e->x_end += SIZE_X / 2;
	e->y_start += SIZE_Y / 2;
	e->y_end += SIZE_Y / 2;
}

void	ft_print_map(t_env *e, int x, int y)
{
	ft_new_image(e);
	while (y < e->y_max)
	{
		while (x < e->x_max)
		{
			if (x + 1 < e->x_max)
			{
				ft_coord_x(e, x, y);
				ft_lines(e);
			}
			if (y + 1 < e->y_max)
			{
				ft_coord_y(e, x, y);
				ft_lines(e);
			}
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "FdF from bfruchar");
	mlx_destroy_image(e->mlx, e->img_ptr);
}
