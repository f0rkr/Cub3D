/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:48:51 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:54:44 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_iswall(float y, float x)
{
	if (x >= 0 && x < g_data.max * TAIL_SIZE && y >= 0 &&
			y < g_data.y_size * TAIL_SIZE)
	{
		if (g_data.map[(int)y / TAIL_SIZE][(int)x / TAIL_SIZE] != '1' &&
				g_data.map[(int)y / TAIL_SIZE][(int)x / TAIL_SIZE] != '2')
			return (1);
	}
	return (0);
}

int		ft_isprt(float y, float x)
{
	if (x >= 0 && x < g_data.x_size * TAIL_SIZE && y >= 0 &&
			y < g_data.y_size * TAIL_SIZE)
	{
		if (g_data.map[(int)y / TAIL_SIZE][(int)x / TAIL_SIZE] != '2')
			return (1);
	}
	return (0);
}

int		ft_iswal(float y, float x)
{
	if (x >= 0 && x < g_data.max * TAIL_SIZE && y >= 0 &&
			y < g_data.y_size * TAIL_SIZE)
	{
		if (g_data.map[(int)y / TAIL_SIZE][(int)x / TAIL_SIZE] != '1' &&
				g_data.map[(int)y / TAIL_SIZE][(int)x / TAIL_SIZE] != '3')
			return (1);
	}
	return (0);
}
