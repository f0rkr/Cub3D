/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:54:35 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:54:37 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			ft_player_error(int i, int j)
{
	int n;

	n = 1;
	j++;
	while (i < g_data.y_size)
	{
		if (n == 0)
			j = 0;
		if (n == 1)
			n = 0;
		while (g_data.map[i][j])
		{
			if (g_data.map[i][j] == 'N' || g_data.map[i][j] == 'S'
					|| g_data.map[i][j] == 'W' || g_data.map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void		ft_maperro(void)
{
	write(1, "Error\n", 6);
	write(1, "map error\n", 10);
	exit(-1);
}

void		ft_erro_map(int i, int j)
{
	if (g_data.map[i][j] == '0')
	{
		if (i + 1 >= g_count)
			return (ft_maperro());
		else if (g_data.map[i][j + 1] == ' ' || g_data.map[i][j + 1]
				== '\0' || g_data.map[i + 1][j] == ' ' || !g_data.map[i - 1][j]
				|| !g_data.map[i - 1][j] || !g_data.map[i + 1][j])
			ft_maperro();
	}
	else if (g_data.map[i][j] == ' ' && (i + 1) < g_count)
	{
		if (g_data.map[i][j + 1] == '0' || g_data.map[i + 1][j] == '0' ||
		g_data.map[i][j + 1] == g_playp || g_data.map[i + 1][j] == g_playp)
			ft_maperro();
	}
	else if (g_data.map[i][j] == g_playp)
	{
		if (ft_player_error(i, j))
			ft_maperro();
		else if (i + 1 >= g_count)
			ft_maperro();
		else if (g_data.map[i][j + 1] == ' ' || g_data.map[i][j + 1] == '\0' ||
g_data.map[i + 1][j] == ' ' || !g_data.map[i - 1][j] || !g_data.map[i + 1][j])
			ft_maperro();
	}
}

int			ft_map_error(void)
{
	int			i;
	int			j;
	static int	n = 0;

	i = -1;
	while (++i < g_count)
	{
		j = -1;
		if (g_data.map[i][0] == '\0')
			ft_maperro();
		while (g_data.map[i][++j])
		{
			(!g_playp) ? ft_maperro() : 0;
			if (n == 0 && (g_data.map[i][j] == '0'
						|| g_data.map[i][j] == g_playp))
				ft_maperro();
			n = 1;
			ft_erro_map(i, j);
			if (g_data.map[i][j] != '0' && g_data.map[i][j] != ' ' &&
					g_data.map[i][j] != '1' && g_data.map[i][j] != '2'
					&& g_data.map[i][j] != g_playp && g_data.map[i][j] != '3')
				ft_maperro();
		}
	}
	return (1);
}
