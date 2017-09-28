/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:51:43 by bfruchar          #+#    #+#             */
/*   Updated: 2017/09/28 14:12:00 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_nothing(char *str)
{
	int		i;
	char	*end;

	i = ft_strlen(str);
	end = &str[i - 4];
	if (i < 5 || ft_strncmp(".fdf", end, 5) != 0)
	{
		ft_putstr("This file isn't compatible, ");
		ft_putstr("try a file \"<filename.fdf>\"\n");
		return (1);
	}
	return (0);
}

int		ft_init_mlx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (1);
	e->win = mlx_new_window(e->mlx, SIZE_X, SIZE_Y, "fdf");
	e->red = 100;
	e->green = 100;
	e->blue = 100;
	e->zoom = 10;
	e->zoom_d = 1;
	e->expose_x = 0.5;
	e->expose_y = 0.25;
	return (0);
}

int		ft_error(int i)
{
	ft_putstr("This is incorrect, you are trying to use");
	ft_putstr(" my fdf with ");
	ft_putnbr(i - 1);
	if (i < 2)
		ft_putstr(" file. You are supposed to use it with one like this:\n");
	else
		ft_putstr(" files. You are supposed to use it with one like this:\n");
	ft_putstr("./fdf <filename.fdf>\n");
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	char	**split;

	split = NULL;
	if (argc != 2)
		return (ft_error(argc));
	if (ft_nothing(argv[1]) == 1)
		return (0);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (ft_init_mlx(e) == 1)
		return (0);
	if (ft_max_x_y(argv[1], e) == 0)
		return (0);
	if (ft_parsing(argv[1], e, 0, split) == 0)
		return (0);
	mlx_hook(e->win, 2, 3, my_key_funct, e);
	mlx_loop_hook(e->mlx, &expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
