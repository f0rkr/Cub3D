/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:28:56 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:54:58 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		ft_player(int x)
{
	g_ply.x = x * TAIL_SIZE + (TAIL_SIZE / 2);
	g_ply.y = g_mlx.y + (TAIL_SIZE / 2);
	g_cot++;
}

void		ft_map(void)
{
	int		x;
	int		y;
	int		k;

	k = 0;
	y = -1;
	while (++y < g_data.y_size)
	{
		x = -1;
		g_mlx.x = 0;
		while (++x < g_data.max)
		{
			if ((g_data.map[y][x] == 'N' || g_data.map[y][x] == 'E'
		|| g_data.map[y][x] == 'W' || g_data.map[y][x] == 'S') && g_cot == 0)
				ft_player(x);
			else if (g_data.map[y][x] == '2')
			{
				g_sprtnum++;
				g_sprt[k].x = x * TAIL_SIZE + (TAIL_SIZE / 2);
				g_sprt[k++].y = g_mlx.y + (TAIL_SIZE / 2);
			}
		}
		g_mlx.y += NOSE_SIZE;
	}
}
