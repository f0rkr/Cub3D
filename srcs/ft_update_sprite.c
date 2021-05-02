/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:58:11 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:58:14 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_sort_array(void)
{
	int		i;
	t_sprt	tmp;

	i = 0;
	while (i < g_sprtnum)
	{
		if (g_sprt[i].distance < g_sprt[i + 1].distance)
		{
			tmp = g_sprt[i];
			g_sprt[i] = g_sprt[i + 1];
			g_sprt[i + 1] = tmp;
		}
		i++;
	}
}

void	ft_update_sprite(int k)
{
	g_sprt[k].distance = sqrt(pow((g_sprt[k].x - g_ply.x), 2)
			+ pow((g_sprt[k].y - g_ply.y), 2));
	ft_sort_array();
}
