/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:56:58 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:57:03 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	render_spt(int x, int y, int sp_size, int k)
{
	int color;
	int i;
	int j;

	i = -1;
	while (++i < sp_size)
	{
		if (x + i < 0 || x + i > g_file.width)
			continue;
		if (g_sprt[k].distance >= g_rays[x + i].distance)
			continue;
		j = -1;
		while (++j < sp_size - 3)
		{
			if ((j * TAIL_SIZE / sp_size) >= 0 && (j * TAIL_SIZE / sp_size)
					< g_file.width && (i * TAIL_SIZE / sp_size) >= 0 &&
					(i * TAIL_SIZE / sp_size) < g_file.height)
				color = g_wall.texture[SPT - 1][TAIL_SIZE *
					(j * TAIL_SIZE / sp_size) + (i * TAIL_SIZE / sp_size)];
			if (color != 0 && (x + i) >= 0 && (x + i) < g_file.width
					&& (y + j) >= 0 && (y + j) < g_file.height)
				g_mlx.img.data[(x + i) + (y + j) * g_file.width] = color;
		}
	}
}

void	ft_sprite(int k)
{
	float sp_size;
	float x_inter;
	float y_inter;
	float p_ang;
	float sp_angle;

	p_ang = (g_direction * CONV);
	ft_update_sprite();
	sp_angle = atan2(g_sprt[k].y - g_ply.y, g_sprt[k].x - g_ply.x);
	while (sp_angle - p_ang > PI)
		sp_angle -= 2 * PI;
	while (sp_angle - p_ang < -PI)
		sp_angle += 2 * PI;
	sp_size = (g_file.width / g_sprt[k].distance) * TAIL_SIZE;
	y_inter = (g_file.height / 2 - sp_size / 2) + g_3d.top;
	x_inter = (sp_angle * INV - p_ang * INV)
		* g_file.width / 60 + (g_file.width / 2 - sp_size / 2);
	render_spt(x_inter, y_inter, sp_size, k);
}
