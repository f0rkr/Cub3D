/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:56:41 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:56:44 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static int		tab_aloc(char *str, char m)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == m)
			i++;
		else
		{
			c++;
			while (str[i] != '\0')
			{
				if (str[i] == m)
					break ;
				i++;
			}
		}
	}
	return (c);
}

static int		string(char *str, int *k, char m)
{
	int c;

	c = 0;
	while (str[*k] != '\0')
	{
		if (str[*k] == m)
			*k += 1;
		else
		{
			while (str[*k] != '\0' && str[*k] != m)
			{
				c++;
				*k += 1;
			}
			*k += 1;
			return (c);
		}
	}
	return (0);
}

static char		**ft_append(char **tab, char *str, int i, char m)
{
	int j;
	int r;

	j = 0;
	while (str[i] != '\0')
	{
		r = 0;
		while (str[i] == m)
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] != m && str[i] != '\0')
		{
			tab[j][r] = str[i];
			i++;
			r++;
			if (str[i] == '\0')
				break ;
		}
		tab[j][r] = '\0';
		j++;
	}
	tab[j] = 0;
	return (tab);
}

static char		**ft_free(char **tab, int r)
{
	while (r)
	{
		free(tab[r]);
		r--;
	}
	free(tab);
	return (NULL);
}

char			**ft_split(char const *str, char c)
{
	char	**tab;
	int		i;
	int		*k;
	int		p;
	int		r;

	r = 0;
	i = 0;
	p = 0;
	k = &p;
	if (!str)
		return (0);
	if (!(tab = ft_malloc(sizeof(char*) * (tab_aloc((char *)str, c) + 1))))
		return (0);
	while (r < tab_aloc((char *)str, c))
	{
		if (!(tab[r] = ft_malloc(sizeof(char)
						* (string((char *)str, k, c) + 1))))
			return (ft_free(tab, r));
		r++;
	}
	ft_append(tab, (char *)str, i, c);
	return (tab);
}
