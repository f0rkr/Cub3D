/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settexture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:49:17 by mashad            #+#    #+#             */
/*   Updated: 2020/03/12 06:56:32 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_bitmap(void)
{
	int i;

	i = 0;
	ft_drawrays();
	ft_render3d();
	while (i < g_sprtnum)
		ft_sprite(i++);
	ft_lifebar();
	bmp();
	exit(0);
}

void	ft_continue(void)
{
	void	*img;
	int		tab[5];

	g_mlx.mlx = mlx_init();
	g_mlx.wind = mlx_new_window(g_mlx.mlx, g_file.width, g_file.height, "cub");
	g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx, g_file.width, g_file.height);
	g_mlx.img.data = (int *)mlx_get_data_addr(g_mlx.img.img_ptr, &g_mlx.img.bpp,
			&g_mlx.img.size_line, &g_mlx.img.endian);
	img = mlx_xpm_file_to_image(g_mlx.mlx, g_text.textso, &tab[0], &tab[1]);
	g_wall.texture[0] = (int *)mlx_get_data_addr(img,
			&tab[2], &tab[3], &tab[4]);
	img = mlx_xpm_file_to_image(g_mlx.mlx, g_text.textea, &tab[0], &tab[1]);
	g_wall.texture[1] = (int *)mlx_get_data_addr(img,
			&tab[2], &tab[3], &tab[4]);
	img = mlx_xpm_file_to_image(g_mlx.mlx, g_text.textno, &tab[0], &tab[1]);
	g_wall.texture[2] = (int *)mlx_get_data_addr(img,
			&tab[2], &tab[3], &tab[4]);
}

void	ft_settexture(void)
{
	void	*img;
	int		tab[5];

	ft_continue();
	img = mlx_xpm_file_to_image(g_mlx.mlx, g_text.textwe, &tab[0], &tab[1]);
	g_wall.texture[3] = (int *)mlx_get_data_addr(img,
			&tab[2], &tab[3], &tab[4]);
	img = mlx_xpm_file_to_image(g_mlx.mlx, g_text.textsp, &tab[0], &tab[1]);
	g_wall.texture[4] = (int *)mlx_get_data_addr(img,
			&tab[2], &tab[3], &tab[4]);
	if (g_save)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.wind);
		ft_bitmap();
	}
}
