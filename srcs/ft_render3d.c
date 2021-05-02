/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 06:56:25 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:56:28 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

float		g_raydist;
float		g_distpj;
float		g_wallstrip;
float		g_top;
float		g_distancetop;
float		g_bottom;
int			g_i;
float		g_j;

void		ft_renha(void)
{
	g_distancetop = g_j - g_top;
	g_wall.txty = (g_distancetop) * ((float)TAIL_SIZE / g_wallstrip);
	if (g_i >= 0 && g_i < g_file.width && g_j >= 0 && g_j < g_file.height)
	{
		if (g_rays[g_i].hitvert && g_rays[g_i].right)
			g_mlx.img.data[(int)g_i + (int)g_j * g_file.width] =
				(g_wall.texture[0][TAIL_SIZE * g_wall.txty + g_wall.txtx]);
		if (g_rays[g_i].hitvert && g_rays[g_i].left)
			g_mlx.img.data[(int)g_i + (int)g_j * g_file.width] =
				g_wall.texture[1][TAIL_SIZE * g_wall.txty + g_wall.txtx];
		if (!g_rays[g_i].hitvert && g_rays[g_i].up)
			g_mlx.img.data[(int)g_i + (int)g_j * g_file.width] =
				g_wall.texture[2][TAIL_SIZE * g_wall.txty + g_wall.txtx];
		if (!g_rays[g_i].hitvert && g_rays[g_i].down)
			g_mlx.img.data[(int)g_i + (int)g_j * g_file.width] =
				g_wall.texture[3][TAIL_SIZE * g_wall.txty + g_wall.txtx];
	}
}

void		ft_renhel(void)
{
	g_raydist = g_rays[g_i].distance *
	cosf(g_rays[g_i].angle - (g_direction * CONV));
	g_wallstrip = (TAIL_SIZE / g_raydist) * g_distpj;
	g_top = (g_file.height / 2) - (g_wallstrip / 2) + g_3d.top;
	g_bottom = g_top + g_wallstrip;
	g_j = 0;
	if (g_rays[g_i].hitvert)
		g_wall.txtx = ((int)g_rays[g_i].wallhy) % TAIL_SIZE;
	else
		g_wall.txtx = ((int)g_rays[g_i].wallhx) % TAIL_SIZE;
	while (g_j < g_top)
	{
		g_distancetop = g_j - g_top;
		g_wall.txty = (int)((float)TAIL_SIZE / g_wallstrip * g_distancetop)
			& (TAIL_SIZE - 1);
		if (g_i >= 0 && g_i < g_file.width && g_j >= 0 && g_j < g_file.height)
			g_mlx.img.data[(int)g_i + (int)g_j * g_file.width] =
		ft_tohex(g_file.ceilling.r, g_file.ceilling.g, g_file.ceilling.b);
		g_j++;
	}
}

void		ft_render3d(void)
{
	g_i = 0;
	g_distpj = (g_file.width / 2) / (tan((30 * CONV)));
	while (g_i < g_file.width)
	{
		ft_renhel();
		while (g_j < g_bottom)
		{
			ft_renha();
			g_j++;
		}
		while (g_j < g_file.height)
		{
			g_distancetop = g_j - g_top;
			g_wall.txty = (int)((float)TAIL_SIZE / g_wallstrip * g_distancetop)
				& (TAIL_SIZE - 1);
			if (g_i >= 0 && g_i < g_file.width && g_j >= 0 &&
				g_j < g_file.height)
				g_mlx.img.data[(int)g_i + (int)g_j * g_file.width] =
					ft_tohex(g_file.floor.r, g_file.floor.g, g_file.floor.b);
			g_j++;
		}
		g_i++;
	}
}
