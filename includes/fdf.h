/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:49:40 by bfruchar          #+#    #+#             */
/*   Updated: 2017/09/28 10:05:41 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define SIZE_X		1500
# define SIZE_Y		1000

typedef struct	s_env{

	void		*mlx;
	void		*win;
	void		*img_ptr;
	int			red;
	int			green;
	int			blue;
	int			x_max;
	int			y_max;
	int			zoom;
	int			zoom_d;
	int			x_start;
	int			x_end;
	int			y_start;
	int			y_end;
	int			**map;
	char		*data;
	double		expose_x;
	double		expose_y;
}				t_env;

void			ft_color_map(int keycode, t_env *e);
int				my_key_funct(int keycode, t_env *e);
void			ft_expo_x_y(int keycode, t_env *e);
void			ft_draw_lines(t_env *e);
int				loop_event(t_env *e);
void			ft_create_image(t_env *e, int n);
int				ft_max_x_y(char *str, t_env *e);
int				ft_strlen_x(char *str);
int				ft_parsing(char *str, t_env *e, int j, char **split);
int				ft_map_in_struct(char **split, int i, int j, t_env *e);
int				ft_init_mlx(t_env *e);
int				expose_hook(t_env *e);
void			ft_new_image(t_env *e);
void			ft_print_map(t_env *e, int x, int y);
void			ft_coord_x(t_env *e, int x, int y);
void			ft_coord_y(t_env *e, int x, int y);
void			ft_put_pixel_in(t_env *e, int y, int x);
void			lines(t_env *e);

#endif
