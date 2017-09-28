/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 12:54:38 by bfruchar          #+#    #+#             */
/*   Updated: 2017/02/02 12:00:20 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_together(char *str, char *temp)
{
	int		i;
	char	*t;

	i = 0;
	if (!str && temp)
	{
		t = ft_strnew(ft_strlen(temp));
		t = ft_strncpy(t, temp, ft_strlen(temp));
		return (t);
	}
	if (!temp && str)
	{
		t = ft_strnew(ft_strlen(str));
		t = ft_strncpy(t, str, ft_strlen(str));
		return (t);
	}
	if (temp && str)
		return (ft_strjoin(str, temp));
	return (0);
}

int		ft_read_str(int fd, char *temp, char **line, char **str)
{
	char	*temp2;
	char	*temp3;

	temp2 = ft_together(*str, temp);
	temp3 = ft_strchr(temp2, '\n');
	ft_strdel(str);
	if (temp3 == NULL)
	{
		*str = ft_strnew(ft_strlen(temp2));
		*str = ft_strncpy(*str, temp2, (ft_strlen(temp2) + 1));
		ft_strdel(&temp);
		ft_strdel(&temp2);
		return (get_next_line(fd, line));
	}
	else
	{
		*line = ft_strnew(ft_strlen(temp2) - ft_strlen(temp3) + 1);
		*line = ft_strncpy(*line, temp2, (ft_strlen(temp2) - ft_strlen(temp3)));
		*str = ft_strnew(ft_strlen(temp3++));
		*str = ft_strncpy(*str, temp3, ft_strlen(temp3));
		ft_strdel(&temp);
		ft_strdel(&temp2);
		return (1);
	}
}

int		ft_read_end_of_stock(char **str, char **line, int fd)
{
	char		*temp;
	char		*temp2;

	temp2 = ft_strnew(ft_strlen(*str));
	temp2 = ft_strncpy(temp2, *str, ft_strlen(*str));
	temp = ft_strchr(temp2, '\n');
	ft_strdel(str);
	if (temp == NULL)
	{
		*line = ft_strnew(ft_strlen(temp2) + 1);
		*line = ft_strncpy(*line, temp2, ft_strlen(temp2));
		if (ft_strcmp(*line, "") != 0)
			return (1);
		return (get_next_line(fd, line));
	}
	*line = ft_strnew(ft_strlen(temp2) - ft_strlen(temp) + 1);
	*line = ft_strncpy(*line, temp2, ft_strlen(temp2) - ft_strlen(temp));
	*str = ft_strnew(ft_strlen(temp++));
	*str = ft_strncpy(*str, temp, ft_strlen(temp));
	ft_strdel(&temp2);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE];
	char			*temp;
	static char		*str;

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if (ret == 0 && str == NULL)
		return (0);
	if (ret == 0)
		return (ft_read_end_of_stock(&str, line, fd));
	if (ret > 0)
	{
		temp = ft_strnew(ret + 1);
		temp = ft_strncpy(temp, buf, ret);
		return (ft_read_str(fd, temp, line, &str));
	}
	return (0);
}
