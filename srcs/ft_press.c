/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:41:16 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:55:27 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_unpress(int key, void *param)
{
	(void)param;
	if (key == 53)
		g_key.exit = -1;
	if (key == 124)
		g_key.rightd = -1;
	if (key == 123)
		g_key.leftd = -1;
	if (key == 0)
		g_key.left = -1;
	if (key == 2)
		g_key.right = -1;
	if (key == 1)
		g_key.back = -1;
	if (key == 13)
		g_key.straight = -1;
	if (key == 126)
		g_key.up = -1;
	if (key == 125)
		g_key.down = -1;
	return (0);
}

int		ft_press(int key, void *param)
{
	(void)param;
	if (key == 53)
		g_key.exit = 1;
	if (key == 124)
		g_key.rightd = 1;
	if (key == 123)
		g_key.leftd = 1;
	if (key == 0)
		g_key.left = 1;
	if (key == 2)
		g_key.right = 1;
	if (key == 1)
		g_key.back = 1;
	if (key == 13)
		g_key.straight = 1;
	if (key == 126)
		g_key.up = 1;
	if (key == 125)
		g_key.down = 1;
	return (0);
}

void	ft_helpupdate(void)
{
	int i;

	i = 0;
	if (g_key.up == 1 && g_3d.top <= 360)
		g_3d.top += 10;
	if (g_key.down == 1 && g_3d.top >= -360)
		g_3d.top -= 10;
	if (g_key.rightd == 1)
		g_direction += 3;
	if (g_key.leftd == 1)
		g_direction -= 3;
	mlx_destroy_image(g_mlx.mlx, g_mlx.img.img_ptr);
	mlx_clear_window(g_mlx.mlx, g_mlx.wind);
	g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx, g_file.width, g_file.height);
	g_mlx.img.data = (int *)mlx_get_data_addr(g_mlx.img.img_ptr,
			&g_mlx.img.bpp, &g_mlx.img.size_line, &g_mlx.img.endian);
	g_mlx.x = 0;
	g_mlx.y = 0;
	ft_drawrays();
	ft_render3d();
	ft_lifebar();
	while (i < g_sprtnum)
		ft_sprite(i++);
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.wind, g_mlx.img.img_ptr, 0, 0);
}

void	ft_halfelp(void)
{
	if (g_key.exit == 1)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.wind);
		exit(0);
	}
	if (g_key.left == 1)
	{
		if (ft_iswall(((g_ply.y - sin((g_direction + 90) * (PI / 180)) * 20)),
					((g_ply.x - cos((g_direction + 90) * (PI / 180)) * 20))))
		{
			g_ply.x -= cos((g_direction + 90) * (PI / 180)) * SPEED;
			g_ply.y -= sin((g_direction + 90) * (PI / 180)) * SPEED;
		}
	}
	if (g_key.right == 1)
	{
		if (ft_iswall(((g_ply.y + sin((g_direction + 90) * (PI / 180)) * 20)),
					((g_ply.x + cos((g_direction + 90) * (PI / 180)) * 20))))
		{
			g_ply.x += cos((g_direction + 90) * (PI / 180)) * SPEED;
			g_ply.y += sin((g_direction + 90) * (PI / 180)) * SPEED;
		}
	}
}

int		ft_update(void)
{
	ft_halfelp();
	if (g_key.back == 1)
	{
		if (ft_iswall(((g_ply.y - sin((g_direction) * (PI / 180)) * 20)),
					((g_ply.x - cos((g_direction) * (PI / 180)) * 20))))
		{
			g_ply.x = g_ply.x - cos((g_direction) * (PI / 180)) * SPEED;
			g_ply.y = g_ply.y - sin((g_direction) * (PI / 180)) * SPEED;
		}
	}
	if (g_key.straight == 1)
	{
		if (ft_iswall(((g_ply.y + sin((g_direction) * (PI / 180)) * 20)),
					((g_ply.x + cos((g_direction) * (PI / 180)) * 20))))
		{
			g_ply.x = g_ply.x + cos((g_direction) * (PI / 180)) * SPEED;
			g_ply.y = g_ply.y + sin((g_direction) * (PI / 180)) * SPEED;
		}
	}
	ft_helpupdate();
	return (0);
}
