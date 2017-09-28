/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:50:27 by bfruchar          #+#    #+#             */
/*   Updated: 2016/11/24 15:52:24 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (j);
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
		if (s[i] == '\0')
			return (j);
	}
	return (j);
}

static int	*ft_count_char(const char *s, int *tab, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (tab);
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
		}
		tab[k++] = j;
		j = 0;
	}
	return (tab);
}

static char	**ft_split(char **end, const char *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (end);
		while (s[i] != c && s[i] != '\0')
		{
			end[k][j] = s[i];
			i++;
			j++;
		}
		end[k][j] = '\0';
		k++;
		j = 0;
	}
	return (end);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		n_word;
	int		*tab;
	char	**end;

	i = 0;
	if (!s)
		return (NULL);
	n_word = ft_count_word(s, c);
	tab = (int *)malloc((sizeof(int)) * n_word + 1);
	if (tab == NULL)
		return (NULL);
	tab = ft_count_char(s, tab, c);
	end = (char **)malloc((sizeof(char *)) * n_word + 1);
	if (!end)
		return (NULL);
	while (i < n_word)
	{
		end[i] = (char *)malloc(sizeof(char) * tab[i]);
		i++;
	}
	end = ft_split(end, s, c);
	end[n_word] = 0;
	return (end);
}
