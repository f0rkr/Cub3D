/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:15:31 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:53:43 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

float		distancebewpoints(float x, float y, float xd, float yd)
{
	return (sqrt(pow((xd - x), 2) + pow(yd - y, 2)));
}

void		ft_helpone(void)
{
	while (g_draws.nhorx >= 0 && g_draws.nhorx <= g_data.max * TAIL_SIZE &&
	g_draws.nhory >= 0 && g_draws.nhory <= g_data.y_size * TAIL_SIZE)
	{
		if (!(ft_iswal(g_draws.nhory -
						g_draws.tocheck, g_draws.nhorx)))
		{
			g_draws.fhwhit = 1;
			g_draws.hwhitx = g_draws.nhorx;
			g_draws.hwhity = g_draws.nhory;
			break ;
		}
		else
		{
			g_draws.nhorx += g_draws.xsps;
			g_draws.nhory += g_draws.ysps;
		}
	}
}

void		ft_halfone(int i)
{
	g_draws.fhwhit = 0;
	g_draws.vwallhit = 0;
	g_draws.rayang = ft_norm(g_draws.rayang);
	g_rays[i].down = (g_draws.rayang > 0) && (g_draws.rayang < PI);
	g_rays[i].up = !g_rays[i].down;
	g_rays[i].right = (g_draws.rayang < (0.5 * PI)) ||
		(g_draws.rayang > 1.5 * PI);
	g_rays[i].left = !g_rays[i].right;
	g_draws.tocheck = g_rays[i].up ? 1 : 0;
	g_draws.yint = floor((g_ply.y / TAIL_SIZE)) * TAIL_SIZE;
	g_draws.yint += (g_rays[i].down) ? TAIL_SIZE : 0;
	g_draws.xint = g_ply.x - ((g_ply.y - g_draws.yint) / tan(g_draws.rayang));
	g_draws.ysps = TAIL_SIZE;
	g_draws.ysps *= (g_rays[i].up) ? -1 : 1;
	g_draws.xsps = g_draws.ysps / tan(g_draws.rayang);
	g_draws.nhorx = g_draws.xint;
	g_draws.nhory = g_draws.yint;
	ft_helpone();
}

void		ft_halftwo(int i)
{
	g_draws.tocheck = g_rays[i].left ? 1 : 0;
	g_draws.xint = floor(g_ply.x / TAIL_SIZE) * TAIL_SIZE;
	g_draws.xint += g_rays[i].right ? TAIL_SIZE : 0;
	g_draws.yint = g_ply.y - (g_ply.x - g_draws.xint) * tan(g_draws.rayang);
	g_draws.xsps = TAIL_SIZE;
	g_draws.xsps *= g_rays[i].left ? -1 : 1;
	g_draws.ysps = g_draws.xsps * tan(g_draws.rayang);
	g_draws.nhorx = g_draws.xint;
	g_draws.nhory = g_draws.yint;
	while (g_draws.nhorx >= 0 && g_draws.nhorx <= g_data.max * TAIL_SIZE &&
		g_draws.nhory >= 0 && g_draws.nhory <= g_data.y_size * TAIL_SIZE)
	{
		if (!(ft_iswal(g_draws.nhory, g_draws.nhorx - g_draws.tocheck)))
		{
			g_draws.vwallhit = 1;
			g_draws.vwhitx = g_draws.nhorx;
			g_draws.vwhity = g_draws.nhory;
			break ;
		}
		else
		{
			g_draws.nhorx += g_draws.xsps;
			g_draws.nhory += g_draws.ysps;
		}
	}
}

void		ft_drawrays(void)
{
	int		i;

	g_draws.fhwhit = 0;
	g_draws.vwallhit = 0;
	g_draws.rayang = (g_direction - 30) * (PI / 180);
	i = -1;
	while (++i < g_file.width)
	{
		ft_halfone(i);
		ft_halftwo(i);
		g_draws.hdistnc = (g_draws.fhwhit) ? distancebewpoints(g_ply.x, g_ply.y,
			g_draws.hwhitx, g_draws.hwhity) : INT32_MAX;
		g_draws.vdistnc = (g_draws.vwallhit)
		? distancebewpoints(g_ply.x, g_ply.y, g_draws.vwhitx, g_draws.vwhity)
			: INT32_MAX;
		g_rays[i].wallhx = (g_draws.hdistnc <
			g_draws.vdistnc) ? g_draws.hwhitx : g_draws.vwhitx;
		g_rays[i].wallhy = (g_draws.hdistnc <
			g_draws.vdistnc) ? g_draws.hwhity : g_draws.vwhity;
		g_rays[i].distance = (g_draws.hdistnc < g_draws.vdistnc) ?
			g_draws.hdistnc : g_draws.vdistnc;
		g_rays[i].angle = g_draws.rayang;
		g_rays[i].hitvert = (g_draws.vdistnc < g_draws.hdistnc);
		g_draws.rayang += (60 * (PI / 180)) / g_file.width;
	}
}
