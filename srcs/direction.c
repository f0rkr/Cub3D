/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:42:49 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:53:19 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			ft_set_ply(char c)
{
	if (c == 'N')
	{
		g_playp = 'N';
		g_direction = 270;
	}
	else if (c == 'E')
	{
		g_playp = 'E';
		g_direction = 0;
	}
	else if (c == 'S')
	{
		g_playp = 'S';
		g_direction = 90;
	}
	else if (c == 'W')
	{
		g_playp = 'W';
		g_direction = 180;
	}
	return (1);
}

void		ft_direction(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_data.y_size)
	{
		j = 0;
		while (g_data.map[i][j])
		{
			if (g_data.map[i][j] == 'N' || g_data.map[i][j] == 'S'
					|| g_data.map[i][j] == 'W' || g_data.map[i][j] == 'E')
				ft_set_ply(g_data.map[i][j]);
			j++;
		}
		i++;
	}
}
