/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:39:28 by bfruchar          #+#    #+#             */
/*   Updated: 2017/09/28 14:22:40 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_strlen_x(char *str)
{
	char	**split;

	split = NULL;
	split = ft_strsplit(str, ' ');
	return (ft_str_tab_len(split));
}

int		ft_max_x_y(char *str, t_env *e)
{
	int		fd;
	char	*line;
	int		lengths;
	int		number_lines;

	e->x_max = 0;
	number_lines = 0;
	fd = 0;
	lengths = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		lengths = ft_strlen_x(line);
		if (e->x_max < lengths)
			e->x_max = lengths;
		number_lines++;
		if (line)
			free(line);
	}
	e->y_max = number_lines;
	close(fd);
	return (1);
}

int		ft_map_in_struct(char **split, int i, int j, t_env *e)
{
	int		x;
	int		r;
	char	**split_two;

	r = 0;
	x = 0;
	split_two = NULL;
	while (split[x] && i != e->x_max)
	{
		split_two = ft_strsplit(split[x], ',');
		e->map[j][i] = ft_atoi(split_two[r]);
		i++;
		x++;
		if (split_two)
			free(split_two);
	}
	if (i != e->x_max)
	{
		ft_putstr("This is not a valid map\n");
		return (0);
	}
	return (1);
}

int		ft_check_file(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ','
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| str[i] == ' ' || str[i] == '-' || str[i] == 'x')
			i++;
		else
		{
			ft_putstr("Some elements are not correct in the file\n");
			return (0);
		}
	}
	return (1);
}

int		ft_parsing_next_next(int j, t_env *e, char **split, int fd)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		if (ft_check_file(line) == 0)
			return (0);
		if (!(e->map[j] = malloc(sizeof(int) * e->x_max)))
			return (0);
		split = ft_strsplit(line, ' ');
		if (split)
			if (ft_map_in_struct(split, 0, j, e) == 0)
				return (0);
		if (split)
			free(split);
		j++;
	}
	return (1);
}

int		ft_parsing_next(char *line, t_env *e, char **split, int fd)
{
	int		j;

	j = 0;
	if (ft_check_file(line) == 0)
		return (0);
	if (!(e->map[j] = malloc(sizeof(int) * e->x_max)))
		return (0);
	split = ft_strsplit(line, ' ');
	if (split)
		if (ft_map_in_struct(split, 0, j, e) == 0)
			return (0);
	if (split)
		free(split);
	j++;
	return (ft_parsing_next_next(j, e, split, fd));
}

int		ft_parsing(char *str, t_env *e, int j, char **split)
{
	int		fd;
	char	*line;

	j = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
	{
		close(fd);
		ft_putstr("This file is not valid\n");
		return (0);
	}
	if (!(e->map = malloc(sizeof(int*) * e->y_max)))
		return (0);
	if (get_next_line(fd, &line) == 1)
	{
		if (ft_parsing_next(line, e, split, fd) == 0)
			return (0);
	}
	else
	{
		ft_putstr("There is nothing interesting in this ");
		ft_putstr("file/directory, try an other one\n");
		return (0);
	}
	close(fd);
	return (1);
}
